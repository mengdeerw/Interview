//directed graph BFS
// time complexity: O(V + E) where V is the number of courses, and E is the number of dependencies.
// space complexity: O(V + E)
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> degree(numCourses, 0);
        
        for (auto e: prerequisites) { //0,1: 1->0
            graph[e[1]].push_back(e[0]);
            degree[e[0]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (degree[i] == 0) q.push(i);
        }
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (auto neighbor: graph[node]) {
                degree[neighbor]--;
                if (degree[neighbor] == 0)
                    q.push(neighbor);
            }
        }
        
        for (int i = 0; i < numCourses; i++) {
            if (degree[i]) return false;
        }
        return true;
    }
};
