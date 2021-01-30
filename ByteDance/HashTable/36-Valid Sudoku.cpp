// METHOD-1: Use hashtable to store the numbers of each row, column and each 3×3 box. If there number appears more than once then it’s an invalid Sudoku.
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            set<char> rows, cols, cube;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.' && !rows.insert(board[i][j]).second) return false;
                if (board[j][i] != '.' && !cols.insert(board[j][i]).second) return false;
                
                int cubeRow = (i / 3)*3 + j / 3;
                int cubeCol = (i % 3)*3 + j % 3; 
                if (board[cubeRow][cubeCol] != '.' && !cube.insert(board[cubeRow][cubeCol]).second)
                    return false;
            }
        }
        return true;
    }
};
// set<type>.insert() 返回的是pair<iterator, bool> 

// METHOD-2: use 3 vectors of bool flags to represent row, col, cube flags.
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row (9, vector<bool>(9));
        vector<vector<bool>> col (9, vector<bool>(9));
        vector<vector<bool>> cube (9, vector<bool>(9));
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int c = board[i][j] - '1';
                int cubeNum = (i / 3) * 3 + j / 3;
                if (row[i][c] || col[c][j] || cube[cubeNum][c]) return false;
                row[i][c] = true;
                col[c][j] = true;
                cube[cubeNum][c] = true;
            }
        }
        return true;
    }
};
