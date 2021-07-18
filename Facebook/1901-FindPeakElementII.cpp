// binary search
// time complexity: O(MlogN)
class Solution {
public:
    /*
     * @param A: An integer matrix
     * @return: The index of the peak
     */
    vector<int> findPeakGrid(vector<vector<int>> &A) {
        int n = A.size();
        int up = 0, bottom = n - 1;
        
        while(up + 1 < bottom) {
            int mid = up + (bottom - up) / 2;
            int index = find_maxCol(A, mid);
            //若上一行位置比当前位置值大，则下边界上移
            if (A[mid][index] < A[mid - 1][index]) {
                bottom = mid;
            }
            //若下一行位置比当前位置值大，则上边界下移
            else if (A[mid][index] < A[mid + 1][index]) {
                up = mid;
            }
            //否则该位置为峰值，直接返回答案
            else {
                return vector<int>{mid, index};
            }
        }

        //比较上下边界上最大值，取较大的位置返回答案
        int bottom_index = find_maxCol(A, bottom);
        int up_index = find_maxCol(A, up);
        if (A[up][up_index] < A[bottom][bottom_index]) {
            return vector<int>{bottom, bottom_index};
        } else {
            return vector<int>{up, up_index};
        }
    }

private:
    //find_maxCol用于找到当前行最大值所在列
    int find_maxCol(vector<vector<int>>& A, int row) {
        int col = 0;
        int m = A[0].size();
        for (int i = 0; i < m; i++) {
            if (A[row][col] < A[row][i]) col = i;
        }
        return col;
    }

};
