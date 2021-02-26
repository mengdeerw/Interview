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

// METHOD-3 union find
// Time complexity : O(n^3). We traverse over the complete matrix once. Union and find operations take O(n) time in the worst case.
// Space complexity : O(n)O(n). parentparent array of size nn is used
class Solution {
public:
    int find(vector<int>& parents, int i) {
        if (parents[i] == -1) return i;
        return find(parents, parents[i]);
    }
    
    void do_union(vector<int>& parents, int x, int y) {
        int rx = find(parents, x);
        int ry = find(parents, y);
        if (rx != ry) {
            parents[rx] = ry;
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> parents (n, -1);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    do_union(parents, i, j);
                }
            }
        }
        
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (parents[i] == -1) result++;
        }
        return result;
    }
};
