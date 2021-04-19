class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

/* for any position, after 90-degree rotation:
(i, j) => (j, n - i - 1)
so this can be divided as two steps:
(1) (i, j) => (j, i)
(2) (j, i) => (j, n - i - 1)


1 2 3    1 4 7    7 4 1
4 5 6 => 2 5 8 => 8 5 2
7 8 9    3 6 9    9 6 3
*/
