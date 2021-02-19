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

// Naive Union Find 
// Time: O(n*m), where m is the number of connections, n is the number of nodes.
// Space: O(n)
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parents(n);
        for (int i = 0; i < n; i++) {
            parents[i] = i; //父节点指针初始指向自己
        }
        int components = n;
        for (auto e: edges) { // for each edge
            int p1 = find(parents, e[0]);
            int p2 = find(parents, e[1]);
            if (p1 != p2) { // merge two trees
                parents[p1] = p2;
                components--;
            }
        }
        return components;
    }
private:
    int find(vector<int>& parents, int i) {
        while (parents[i] != i) { // 根节点parents[x] == x
            i = parents[i];
        }
        return i; // without path compression
    }
};

// Union Find w/ path compression 
// Time: O(n+mlogn), where m is the number of connections, n is the number of nodes.
// Space: O(n)
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parents(n);
        for (int i = 0; i < n; i++) {
            parents[i] = i; //父节点指针初始指向自己
        }
        int components = n;
        for (auto e: edges) { // for each edge
            int p1 = find(parents, e[0]);
            int p2 = find(parents, e[1]);
            if (p1 != p2) { // merge two trees
                parents[p1] = p2;
                components--;
            }
        }
        return components;
    }
private:
    int find(vector<int>& parents, int i) {
        while (parents[i] != i) { // 根节点parents[x] == x
            parents[i] = parents[parents[i]];
            i = parents[i];
        }
        return i;
    }
};
