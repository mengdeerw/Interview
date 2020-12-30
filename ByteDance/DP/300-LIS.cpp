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

// Binary Search (Patience sorting)
// Time complexity: O(NlogN)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> top (nums.size(), 0);
        int piles = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            int poker = nums[i];
            int left = 0, right = piles;
            while (left < right) {
                int mid = (left + right) / 2;
                if (top[mid] > poker) {
                    right = mid;
                } else if (top[mid] < poker) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            
            // 新建牌堆
            if (left == piles) piles++;
            top[left] = poker;
        }
        
        return piles;
    }
};
