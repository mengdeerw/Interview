// METHOD-1: DFS
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.size() < 1 || grid[0].size() < 1) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited (m, vector<bool> (n));
        int result = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result = max(result, dfs(grid, visited, i, j));
            }
        }
        return result;
    }
    
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
           visited[i][j] || grid[i][j] == 0) {
            return 0;
        }
        visited[i][j] = true;
        int a1 = dfs(grid, visited, i - 1, j);
        int a2 = dfs(grid, visited, i + 1, j);
        int a3 = dfs(grid, visited, i, j - 1);
        int a4 = dfs(grid, visited, i, j + 1);
        return 1 + a1 + a2 + a3 + a4;
    }
};

// METHOD-2: BFS
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.size() < 1 || grid[0].size() < 1) return 0;
        int m = grid.size(), n = grid[0].size();
        int max_area = 0;
        vector<vector<bool>> visited (m, vector<bool>(n, false));
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int area = 1;
                    visited[i][j] = true;
                    q.push({i, j});
                    while (!q.empty()) {
                        auto p = q.front();
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int r = p.first + dirs[k][0];
                            int c = p.second + dirs[k][1];
                            if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] && !visited[r][c]) {
                                visited[r][c] = true;
                                area++;
                                q.push({r, c});
                            }
                        }
                    }
                    max_area = max(max_area, area);
                } 
            }
        }
        return max_area;
    }
};
