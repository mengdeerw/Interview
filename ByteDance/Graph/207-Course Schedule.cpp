// BFS
/*
定义二维数组 graph 来表示这个有向图，一维数组degree来表示每个顶点的入度。开始先根据输入来建立这个有向图，并将入度数组也初始化好。然后将所有入度为0的点放入队列中，遍历队列，从 graph 里遍历其连接的点，每到达一个新节点，将其入度减一，如果此时该点入度为0，则放入队列末尾。直到遍历完队列中所有的值，若此时还有节点的入度不为0，则说明环存在，返回 false，反之则返回 true。
*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph (numCourses);
        vector<int> degree (numCourses);
        // build graph and record indegree
        for (auto e: prerequisites) {
            graph[e[1]].push_back(e[0]);
            degree[e[0]]++;
        }
        queue<int> q;
        // push into the queue if the vertex is with 0 indegree
        for (int i = 0; i < numCourses; i++) {
            if (degree[i] == 0) q.push(i);
        }
        // traverse queue
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto v: graph[node]) {
                degree[v]--;
                if (degree[v] == 0) q.push(v);
            }
        }
        for (int i = 0; i < numCourses; i++) {
            if (degree[i] != 0) return false;
        }
        return true;
    }
};

// DFS
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph (numCourses);
        vector<int> visited (numCourses);
        for (auto e: prerequisites) {
            graph[e[1]].push_back(e[0]);
        }
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(graph, visited, i)) return false;
        }
        return true;
    }
    
    // 0: unknown; 1: visiting; 2: visited
    bool dfs(vector<vector<int>>& graph, vector<int>& visited, int i) {
        if (visited[i] == 2) return false;
        if (visited[i] == 1) return true;
        visited[i] = 2;
        for (auto v: graph[i]) {
            if (!dfs(graph, visited, v)) return false;
        }
        visited[i] = 1;
        return true;
    }
};

// another version of BFS
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph (numCourses);
        vector<int> degree(numCourses, 0);
        for (auto edge: prerequisites) {
            graph[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (degree[i] == 0) {
                q.push(i);
            }
        }
        int count = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            count++;
            for (auto v: graph[u]) {
                degree[v]--;
                if (degree[v] == 0) {
                    q.push(v);
                }
            }
        }
        return count == numCourses;
    }
};
