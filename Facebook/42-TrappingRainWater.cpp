// dynamic programming
// time complexity: O(N)
// space complexity: O(N)
class Solution {
public:
    int trap(vector<int>& heights) {
        if (heights.empty()) return 0;
        int len = heights.size();
        vector<int> left_max(len), right_max(len);
        
        left_max[0] = heights[0];
        for (int i = 1; i < len; i++) {
            left_max[i] = std::max(left_max[i - 1], heights[i]); 
        }

        right_max[len - 1] = heights[len - 1];
        for (int i = len - 2; i >= 0; i--) {
            right_max[i] = std::max(right_max[i + 1], heights[i]);
        }

        int result = 0;
        for (int i = 0; i < len; i++) {
            result += std::min(left_max[i], right_max[i]) - heights[i];
        }
        return result;
    }
};
