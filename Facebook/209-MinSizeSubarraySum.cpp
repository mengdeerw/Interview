// two pointers
// 1. if prefix[j] - prefix[i] >= k, then we know sum of nums[i...j] meets the requirement, calculate and update the length j - i + 1
// 2. while running sum >= k, keep moving left pointer i to the right, if running sum is less than s, then keep moving right pointer j to the right until running sum is >= k
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_len = INT_MAX;
        int n = nums.size(), prefix = 0;
        int i = 0;
        for (int j = 0; j < n; j++) {
            prefix += nums[j]; // update the prefix sum
            while (prefix >= target) {
                min_len = min(min_len, j - i + 1);
                // move left pointer to the right until hit the first bad i
                prefix -= nums[i];
                i++;
            }
        }
        return min_len == INT_MAX ? 0 : min_len;
    }
};
