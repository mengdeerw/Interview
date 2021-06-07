// brute force
// time complexity: O(N^2)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int max_sum = INT_MIN;
        
        for (int i = 0; i < n; i++) {
            int cur_sum = 0; // sum of nums[i...j]
            for (int j = i; j < n; j++) {
                cur_sum += nums[j];
                max_sum = max(max_sum, cur_sum);
            }
        }
        return max_sum;
    }
};

// dp
// time complexity: O(N)
// space complexity: O(N)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0); // dp[i] = max sum in range nums[0...i - 1]
        dp[0] = nums[0];
        
        for (int i = 1; i < n; i++) {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};

// dp
// time complexity: O(N)
// space complexity: O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int cur_sum = nums[0], max_sum = nums[0];
        
        for (int i = 1; i < n; i++) {
            cur_sum = max(cur_sum + nums[i], 0 + nums[i]); // if cur_sum is negative, throw it away and start a new count
            max_sum = max(max_sum, cur_sum);
        }
        return max_sum;
    }
};
