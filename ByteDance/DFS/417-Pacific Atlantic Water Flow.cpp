// METHOD-1: BFS
// Time complexity: O(M*N)
class Solution {
public:
    int m, n;
    vector<vector<int>> heights;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> result;
        if (matrix.empty() || matrix[0].empty()) return result;
        
        m = matrix.size(), n = matrix[0].size();
        heights = matrix; // make a copy of original matrix
        
        queue<pair<int, int>> qp;
        queue<pair<int, int>> qa;
        
        //rows
        for (int i = 0; i < m; i++) {
            qp.push({i, 0}); // left
            qa.push({i, n - 1}); // right
        }
        //cols
        for (int j = 0; j < n; j++) {
            qp.push({0, j}); // top
            qa.push({m - 1, j}); // bottom
        }
        
        vector<vector<bool>> vp (m, vector<bool>(n, false)); 
        vector<vector<bool>> va (m, vector<bool>(n, false));
    
        bfs(qp, vp);
        bfs(qa, va);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vp[i][j] && va[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
    
private:
    void bfs(queue<pair<int, int>>& q, vector<vector<bool>>& visited) {
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            visited[i][j] = true;
            for (auto dir: dirs) {
                int ii = i + dir[0];
                int jj = j + dir[1];
                if (ii < 0 || jj < 0 || ii >= m || jj >= n) continue;
                if (visited[ii][jj]) continue;
                if (heights[ii][jj] < heights[i][j]) continue; // not enough height
                q.push({ii, jj});
            }
        }
    }
};

// METHOD-2：DFS
// Time complexity: O(M*N)
class Solution {
public:
    int m, n;
    vector<vector<int>> heights;
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> result;
        if (matrix.empty() || matrix[0].empty()) return result;
        
        m = matrix.size(), n = matrix[0].size();
        heights = matrix; // make a copy of original matrix
        
        vector<vector<bool>> vp (m, vector<bool>(n, false)); 
        vector<vector<bool>> va (m, vector<bool>(n, false));
        //rows
        for (int i = 0; i < m; i++) {
            dfs(i, 0, vp, 0);
            dfs(i, n - 1, va, 0);
        }
        //cols
        for (int j = 0; j < n; j++) {
            dfs(0, j, vp, 0);
            dfs(m - 1, j, va, 0);
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vp[i][j] && va[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
    
private:
    void dfs(int i, int j, vector<vector<bool>>& visited, int h) {
        if (i < 0 || j < 0 || i >= m || j >= n) return;
        if (heights[i][j] < h || visited[i][j]) return;
        visited[i][j] = true;
        dfs(i + 1, j, visited, heights[i][j]);
        dfs(i - 1, j, visited, heights[i][j]);
        dfs(i, j + 1, visited, heights[i][j]);
        dfs(i, j - 1, visited, heights[i][j]);
    }
};

// METHOD-3: DFS version2
// Time complexity: O(M*N)
class Solution {
public:
    int m, n;
    vector<vector<int>> heights;
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> result;
        if (matrix.empty() || matrix[0].empty()) return result;
        
        m = matrix.size(), n = matrix[0].size();
        heights = matrix; // make a copy of original matrix
        
        vector<vector<bool>> vp (m, vector<bool>(n, false)); 
        vector<vector<bool>> va (m, vector<bool>(n, false));
        //rows
        for (int i = 0; i < m; i++) {
            dfs(i, 0, vp);
            dfs(i, n - 1, va);
        }
        //cols
        for (int j = 0; j < n; j++) {
            dfs(0, j, vp);
            dfs(m - 1, j, va);
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vp[i][j] && va[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
    
private:
    void dfs(int i, int j, vector<vector<bool>>& visited) {
        visited[i][j] = true;
        for (auto dir: dirs) {
            int ii = i + dir[0];
            int jj = j + dir[1];
            if (ii < 0 || jj < 0 || ii >= m || jj >= n) continue;
            if (visited[ii][jj]) continue;
            if (heights[ii][jj] < heights[i][j]) continue;
            dfs(ii, jj, visited);
        }
    }
};
