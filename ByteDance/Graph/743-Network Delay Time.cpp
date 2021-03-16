// METHOD-1: dijkstra
// Time complexity: O((V+E)logV)
class Solution {
public:
    struct cmp {
        bool operator()(pair<int, int> a, pair<int, int> b){
            return a.second > b.second;
        }
    };
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph (n + 1);
        for (auto time: times) {
            graph[time[0]].push_back({time[1], time[2]});
        }
        
        vector<int> dist (n + 1, INT_MAX);
        dist[0] = 0;
        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        pq.push({k, 0});
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int u = p.first;
            for (auto& pair: graph[u]) {
                int v = pair.first, cost = pair.second;
                if (dist[v] > dist[u] + cost) {
                    dist[v] = dist[u] + cost;
                    pq.push({v, dist[v]});
                }
            }
        }
        int result = 0;
        for (auto d: dist) {
            result = max(result, d);
        }
        return result == INT_MAX ? -1 : result;
    }
};
// METHOD-2: dfs
// Time complexity: O(V^2)
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph (n + 1);
        for (auto time: times) {
            graph[time[0]].push_back({time[1], time[2]});
        }
        
        vector<int> dist (n + 1, INT_MAX);
        dfs(graph, dist, k, 0);
        
        int result = 0;
        for (int i = 1; i <= n; i++) {
            result = max(result, dist[i]);
        }
        return result == INT_MAX ? -1 : result;
    }
    
    void dfs(vector<vector<pair<int, int>>>& graph, vector<int>& dist, int u, int time) {
        if (time >= dist[u]) return;
        dist[u] = time;
        for (auto pair: graph[u]) {
            int v = pair.first, cost = pair.second;
            dfs(graph, dist, v, time + cost);
        }
    }
};
