class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0 && j > 0 && matrix[i][j] != matrix[i - 1][j - 1]) return false;
            }
        }
        return true;
    }
};

// follow up: if you have limited memory to only load one row of the matrix at a time
// solution: use hashmap
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        unordered_map<int, int> m;
        for (int r = 0; r < matrix.size(); r++) {
            for (int c = 0; c < matrix[0].size(); c++) {
                if (m.count(r - c) == 0) {
                    m[r - c] = matrix[r][c];
                } else {
                    if (matrix[r][c] != m[r - c]) return false;
                }
            }
        }
        return true;
    }
};
