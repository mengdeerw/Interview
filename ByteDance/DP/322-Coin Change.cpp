// dp 数组的迭代解法: 自底而上，bottom-up
// Time complexity: O(NK) where N is the size of dp[], K is the size of coins array
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp (amount + 1, amount + 1);
        // dp[i] : the minimum number of coins inorder to get the amount of i
        // initial value is amount + 1: to reach amount, the maximum coin number is amount, so amount + 1 makes sure the dp[] is initialized with maximum values to be updated later
        dp[0] = 0;
        // 外层 for 循环在遍历所有状态的所有取值
        for (int i = 0; i < dp.size(); i++) {
            // 内层 for 循环在求所有选择的最小值
            for (int coin: coins) {
                // 子问题无解，coin值比所需面值还大
                if (i < coin) continue;
                /*更新dp[i]的最小值（比如你想求 amount = 11 时的最少硬币数（原问题），
                如果你知道凑出 amount = 10 的最少硬币数（子问题），你只需要把子问题的答案加一（再选一枚面值为 1 的硬币）
                就是原问题的答案）*/
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
        return (dp[amount] == amount + 1) ? -1 : dp[amount];
    }
};
