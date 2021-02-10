// BFS
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph (n);
        vector<bool> visited (n);
        for (auto e: edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            result++;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                visited[node] = true;
                for (auto neighbor: graph[node]) {
                    if (!visited[neighbor])
                        q.push(neighbor);
                }
            }
        }
        return result;
    }
};

// DFS
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph (n);
        vector<bool> visited (n, false);
        for (auto e: edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            result++;
            dfs(graph, i, visited);
        }
        return result;
    }
    
    void dfs(vector<vector<int>>& graph, int root, vector<bool>& visited) {
        if (visited[root]) return;
        visited[root] = true;
        for (auto neighbour: graph[root]) {
            if (!visited[neighbour]) {
                dfs(graph, neighbour, visited);
            }
        }
    }
};
