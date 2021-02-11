// topological sort
// Time complexity: Time Complexity: O(V + E) where VV represents the number of vertices and EE represents the number of edges. Essentially we iterate through each node and each vertex in the graph once and only once.
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result;
        vector<vector<int>> graph (numCourses);
        vector<int> degree (numCourses, 0);
        for (auto p: prerequisites) {
            graph[p[1]].push_back(p[0]);
            degree[p[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (degree[i] == 0) q.push(i);
        }
        
        while (!q.empty()) {
            int course = q.front();
            result.push_back(course);
            q.pop();
            for (auto v: graph[course]) {
                degree[v]--;
                if (degree[v] == 0) q.push(v);
            }
        }
        return numCourses == result.size() ? result : vector<int>();
    }
};
