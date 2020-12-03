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
