// METHOD-1: dp
// define dp[i] as the longest length of LCIS in range[0...i]
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        int result = 1;
        vector<int> dp (n, 1); // single number itself is a subsequence
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            }
            result = max(result, dp[i]);
        }
        return result;
    }
};

// METHOD-2: greedy
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() < 1) return 0;
        int count = 1; // single number
        int max_len = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                count++;
            } else {
                count = 1; // reset
            }
            max_len = max(max_len, count);
        }
        return max_len;
    }
};
