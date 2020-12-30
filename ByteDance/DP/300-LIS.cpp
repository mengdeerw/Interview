// dp
// Time complexity: O(N^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // dp表示以nums[i]结尾的最长递增子序列的长度
        vector<int> dp (nums.size(), 1); 
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) { //找到比nums[i]小的子序列，将nums[j]接到最后形成新的子序列
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        
        int result = 0;
        for (int i = 0; i < dp.size(); i++) {
            result = max(result, dp[i]);
        }
        return result;
    }
};
