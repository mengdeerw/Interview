// METHOD-1: dfs
// Time complexity: O(N^2)
// Space complexity: O(N) (visited array of size n)
class Solution {
public:
    void dfs(vector<vector<int>>& matrix, vector<int>& visited, int i) {
        for (int j = 0; j < matrix.size(); j++) {
            if (matrix[i][j] == 1 && !visited[j]) {
                visited[j] = 1;
                dfs(matrix, visited, j);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n);
        int result = 0;
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(isConnected, visited, i);
                result++;
            }
        }
        return result;
    }
};

// METHOD-2: BFS
// Time complexity: O(N^2)
// Space complexity: O(N) (queue of size n)
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n);
        int result = 0;
        queue<int> q;
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                q.push(i);
                result++;
                while (!q.empty()) {
                    int curr = q.front();
                    q.pop();
                    visited[curr] = 1;
                    for (int j = 0; j < n; j++) {
                        if (isConnected[curr][j] == 1 && !visited[j]) {
                            q.push(j);
                        }
                    }
                }
            }
        }
        return result;
    }
};
