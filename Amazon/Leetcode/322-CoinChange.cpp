// top down method:
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 1) return 0;
        vector<int> count(amount);
        return coinChange(coins, amount, count);
    }
    
    int coinChange(vector<int>& coins, int remain, vector<int>& count) {
        if (remain < 0) return -1;
        if (remain == 0) return 0;
        if (count[remain - 1] != 0) return count[remain - 1];
        int min = INT_MAX;
        for (int coin: coins) {
            int res = coinChange(coins, remain - coin, count);
            if (res >= 0 && res < min) min = res + 1;
        }
        count[remain - 1] = (min == INT_MAX) ? -1 : min;
        return count[remain - 1];
    }
};

// bottom up method:
// define dp[i]: the fewest number of coins that will reach the amount as i
// dp[i] = dp[i - previous coin amount]
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1); 
        dp[0] = 0;
        for (int i = 1; i < dp.size(); i++) {
            for (int coin: coins) {
                if (i == coin) continue;
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};
