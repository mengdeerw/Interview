// backtrack
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board, 0, 0);
    }
    
    bool backtrack(vector<vector<char>>& board, int i, int j) {
        int m = 9, n = 9;
        
        // reach the last column, switch to next row
        if (j == n) return backtrack(board, i + 1, 0);
        // reach the last row, complete
        if (i == m) return true;
        if (board[i][j] != '.') return backtrack(board, i, j + 1);
        
        // fill sodoku
        for (char c = '1'; c <= '9'; c++) {
            if (!isValid(board, i, j, c)) continue;
            
            board[i][j] = c;
            if (backtrack(board, i, j + 1)) return true;
            board[i][j] = '.'; //reset
        }
        return false;
    }
    
    bool isValid(vector<vector<char>>& board, int r, int c, char ch) {
        for (int i = 0; i < 9; i++) {
            if (board[r][i] == ch) return false;
            if (board[i][c] == ch) return false;
            if (board[(r/3)*3 + i/3][(c/3)*3 + i%3] == ch) return false;
        }
        return true;
    }
};
