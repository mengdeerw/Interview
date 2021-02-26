// DFS
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
