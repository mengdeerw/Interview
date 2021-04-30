// dp + two pass iteration
// Time complexity: O(N)
// Space complexity: O(N)
/*
1.Find maximum height of bar from the left end upto an index i in the array left_max.
2.Find maximum height of bar from the right end upto an index i in the array right_max.
3.Iterate over the \text{height}height array and update ans:
  Add min(left_max[i], right_max[i]) - height[i] to ans
*/
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        int result = 0;
        int size = height.size();
        vector<int> left_max(size), right_max(size);
        left_max[0] = height[0];
        for (int i = 1; i < size; i++) {
            left_max[i] = max(height[i], left_max[i - 1]);
        }
        right_max[size - 1] = height[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            right_max[i] = max(height[i], right_max[i + 1]);
        }
        
        for (int i = 0; i < size; i++) {
            result += min(left_max[i], right_max[i]) - height[i];
        }
        return result;
    }
};
