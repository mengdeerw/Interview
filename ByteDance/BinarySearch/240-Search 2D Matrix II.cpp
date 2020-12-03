// METHOD-1 Search from top right element
// Time complexity: O(M + N)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //starting from top right element
        int row = matrix.size() - 1, col = matrix[0].size() - 1;
        int i = 0, j = col;
        while (i <= row && j >= 0) {
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] < target) i++;
            else if (matrix[i][j] > target) j--;
        }
        return false;
    }
};

// METHOD-2 Binary Search + divide and conquer
// Time complexity: O(MlogN)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return search(matrix, target, 0, matrix.size() - 1);
    }
    
    bool search(vector<vector<int>>& matrix, int target, int top, int bottom) {
        if (top > bottom) return false;
        
        int mid = top + (bottom - top) / 2;
        // first search in the row of matrix[mid]
        if (matrix[mid][0] <= target && target <= matrix[mid].back())
            // search in the same row
            if (searchRow(matrix[mid], target)) return true;
        
        // do the rest of the matrix
        if (search(matrix, target, top, mid - 1)) return true;
        if (search(matrix, target, mid + 1, bottom)) return true;
        return false;
    }
    
    bool searchRow(vector<int>& row, int target) {
        int left = 0, right = row.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (row[mid] == target) return true;
            if (row[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return false;
    }
};

//METHOD-3 DIVIDE AND CONQUER APPROACH
//Time complexity: O(nlogn)

class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return searchRect(matrix, target, 0, 0, matrix.size() - 1, matrix[0].size() - 1);
    }

    bool searchRect(vector<vector<int>>& matrix, int target, 
                               int top, int left, int bottom, int right) {
        
        if(top>bottom || left>right)
            return false;
        
        int x = (top + bottom) / 2;
        int y = (left + right) / 2;
        int center = matrix[x][y];
        
        if(center > target){
            return
                searchRect(matrix, target, top, left, x - 1, right) ||
                searchRect(matrix, target, x, left, bottom, y - 1);
        }
        else if(center < target){
            return
                searchRect(matrix, target, x + 1, left, bottom, right) ||
                searchRect(matrix, target, top, y + 1, x, right);
        }
        else
            return true;
    }
};

// METHOD-4 BINARY SEARCH SOLUTION: 
// Time complexity: O(nlogn)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] <= target && target <= matrix[i][n - 1]) {
                int left = 0, right = n - 1;
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (matrix[i][mid] == target) return true;
                    else if (matrix[i][mid] > target) right = mid - 1;
                    else left = mid + 1;
                }
            }
        }
        return false;
    }
};
