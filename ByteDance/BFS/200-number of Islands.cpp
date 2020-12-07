// BFS
// Time: O(M*N)
// Space: O(min(m, n))
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int result = 0;
        vector<vector<bool>> visited (m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        vector<vector<int>> dirs {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    visited[i][j] = true;
                    result++;
                    
                    // bfs
                    q.push({i, j});
                    while (!q.empty()) {
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();
                        for (auto dir: dirs) {
                            int rr = r + dir[0], cc = c + dir[1];
                            if (rr >= 0 && cc >= 0 && rr < m && cc < n && grid[rr][cc] == '1' && !visited[rr][cc]) {
                                visited[rr][cc] = true;
                                q.push({rr, cc});
                            }
                        }
                    }
                }
            }
        }
        return result;
    }
};

// DFS
// Time: O(M*N)
// Space: O(M*N)
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited (m, vector<bool>(n, false));
        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    dfs(grid, i, j, m, n, visited);
                    result++;
                }
            }
        }
        return result;
    }
    
    void dfs(vector<vector<char>>& grid, int i, int j, int& m, int& n, vector<vector<bool>>& visited) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0' || visited[i][j]) return;
        visited[i][j] = true;
        dfs(grid, i + 1, j, m, n, visited);
        dfs(grid, i - 1, j, m, n, visited);
        dfs(grid, i, j + 1, m, n, visited);
        dfs(grid, i, j - 1, m, n, visited);
    }
};
