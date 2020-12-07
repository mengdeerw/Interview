class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = m ? matrix[0].size() : 0;
        int up = 0, bot = m - 1, l = 0, r = n - 1;
        vector<int> result (m * n);
        
        int curr = 0;
        while (up <= bot && l <= r) {
            for (int col = l; col <= r; col++) // up
                result[curr++] = matrix[up][col]; 
            if (++up > bot) break;
            
            for (int row = up; row <= bot; row++) // right
                result[curr++] = matrix[row][r]; 
            if (--r < l) break;
            
            for (int col = r; col >= l; col--) //bottom
                result[curr++] = matrix[bot][col]; 
            if (--bot < up) break;
            
            for (int row = bot; row >= up; row--) //left
                result[curr++] = matrix[row][l]; 
            if (l++ > r) break;
        }
        return result;
    }
};
