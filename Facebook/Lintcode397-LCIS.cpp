// define dp[i] as the longest length of LCIS in range[0...i]
class Solution {
public:
    /**
     * @param A: An array of Integer
     * @return: an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int> &nums) {
        int n = nums.size();
        if (n < 1) return 0;
        if (n == 1) return 1;
        int result = 1;
        vector<int> dp (n, 1); // single number itself is a subsequence
        // left to right
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            }
            result = max(result, dp[i]);
        }
        dp.resize(n, 1);
        // right to left
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i + 1] < nums[i]) {
                dp[i] = dp[i + 1] + 1;
            }
            result = max(result, dp[i]);
        }
        return result;
    }
};

// better version:
class Solution {
public:
    /**
     * @param A: An array of Integer
     * @return: an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int> &A) {
        if (A.size() == 0) return 0;
        int pos = helper(A);
        reverse(A.begin(), A.end());
        int neg = helper(A);
        return max(pos, neg);
    }
    
    int helper(vector<int>& A) {
        int n = A.size();
        vector<int> dp(n, 1);
        int result = 1;
        for (int i = 1; i < n; ++i) {
            if (A[i] > A[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            }
            result = max(result, dp[i]);
        }
        return result;
    }
};
