/*
Time complexity: O(N!) 
There is N possibilities to put the first queen, not more than N (N - 2) to put the second one, 
not more than N(N - 2)(N - 4) for the third one etc. In total that results in O(N!) time complexity.
Space complexity : O(N) to keep an information about diagonals and rows.
*/

class Solution {
public:
    vector<vector<string>> result;
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board (n, string(n, '.'));
        backtrack(board, 0);
        return result;
    }
    
    void backtrack(vector<string>& board, int row) {
        if (row == board.size()) {
            result.push_back(board);
            return;
        }
        int n = board[row].size();
        for (int col = 0; col < n; col++) {
            if (!isValid(board, row, col)) 
                continue;
            board[row][col] = 'Q';
            backtrack(board, row + 1);
            // reset
            board[row][col] = '.';
        }
    }
    
    
    bool isValid(vector<string>& board, int row, int col) {
        int n = board.size();
        
        // check if there is any 'Q' in this col
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;  
        }
        // check if any 'Q' in the right-up corner
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }
        // check if any 'Q' in the left-up corner 
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
        // since we scan from up to down, no neeed to check board that are below this row..
        return true;
    }
};
