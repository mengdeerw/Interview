// solution is straight-forward, what if we don't have much space to save all the elements in the matrix?
// what the interviewer is expecting actually is how to compress the sparse matrices
// we can skip saving elements whose values are zero
// METHOD: 2 vectors to store index and value of all the non-zero elements in the matrices.
// Time complexity: O(M + N) where M and N are the numbers of non-zero elements in the matrices.
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size(), n = A[0].size(), k = B[0].size(); // A[0].size() == B.size()
        vector<vector<int>> result (m, vector<int> (k, 0));
        
        vector<vector<pair<int, int>>> sparseA (m, vector<pair<int, int>>()); // map column index and non-zero values 
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i][j]) {
                    sparseA[i].push_back({j, A[i][j]});
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (auto a: sparseA[i]) {
                int index = a.first, num = a.second;
                for (int j = 0; j < k; j++) {
                    if (B[index][j]) {
                        result[i][j] += num*B[index][j];
                    }
                }
            }
        }
        return result;
    }
};

// improvement: only save the column index of matrix A for each row.
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size(), n = A[0].size(), k = B[0].size(); // A[0].size() == B.size()
        vector<vector<int>> result (m, vector<int> (k, 0));
        
        //vector<vector<pair<int, int>>> sparseA (m, vector<pair<int, int>>()); // map column index and non-zero values 
        vector<vector<int>> sparseA (m);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i][j]) {
                    sparseA[i].push_back(j);
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int index: sparseA[i]) {
                for (int j = 0; j < k; j++) {
                    if (B[index][j]) {
                        result[i][j] += A[i][index]*B[index][j];
                    }
                }
            }
        }
        return result;
    }
};
