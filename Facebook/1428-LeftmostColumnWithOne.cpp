/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

// METHOD-1: binary search
// time complexity: O(MlogN)
class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> size = binaryMatrix.dimensions();
        int m = size[0], n = size[1];
        int min_col = INT_MAX;
        for (int row = 0; row < m; row++) {
            // binary search to find the index of leftmost 1 in each row
            int start = 0, end = n - 1;
            while (start < end) {
                int mid = start + (end - start) / 2;
                if (binaryMatrix.get(row, mid)) {
                    end = mid; // cut off all the elements that are equal to 1, until we find the leftmost position of 1
                } else {
                    start = mid + 1; // we know mid is not the element we are finding, so skip it.
                }
            }
            // at here, start == end
            if (binaryMatrix.get(row, start)) {
                min_col = min(min_col, start);
            }
        }
        return min_col == INT_MAX ? -1 : min_col;
    }
};


// METHOD-2: optimal linear search
// time complexity: O(N + M)
// start from top right corner, if the current element is 1, move to left; otherwise move downwards; keep checking
class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> size = binaryMatrix.dimensions(); 
        int rows = size[0], cols = size[1];
        int r = 0, c = cols - 1;
        while (r < rows && c >= 0) {
            if (binaryMatrix.get(r, c)) c--;
            else r++;
        }
        return c == cols - 1 ? -1 : c + 1;
    }
};
