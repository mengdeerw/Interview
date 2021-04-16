// DFS
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        if (color != newColor) {
            dfs(image, sr, sc, color, newColor);
        }
        return image;
    }
    
    void dfs(vector<vector<int>>& image, int r, int c, int color, int newColor) {
        if (r < 0 || c < 0 || r == image.size() || c == image[0].size()) return;
        if (image[r][c] == color) {
            image[r][c] = newColor;
            dfs(image, r + 1, c, color, newColor);
            dfs(image, r - 1, c, color, newColor);
            dfs(image, r, c + 1, color, newColor);
            dfs(image, r, c - 1, color, newColor);
        }
    }
};
