// Q121 买卖股票1 ONLY one transaction
// METHOD-1: brute force
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxGain = 0;
        for (int i = 0; i < prices.size() - 1; i++) {
            for (int j = i + 1; j < prices.size(); j++) {
                maxGain = max(maxGain, prices[j] - prices[i]);
            }
        }
        return maxGain;
    }
};

// METHOD-2: DP
// dynamically update the lowest stock price in so far range [0, i] 
// & the highest profit in so far range[0, i]
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX, maxGain = INT_MIN;
        for (int i = 0; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);
            maxGain = max(maxGain, prices[i] - minPrice);
        }
        return maxGain;
    }
};

// Q122 买卖股票2 mutiple transactions
// find the peak and valley price in so far range:
// gradually move the pointer to find the peak and valley, and update the max profit so far
// more efficient way: use pointer to find the max peak and min valley until the next prices is in opposite direction
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int valley = prices[0], peak = prices[0];
        int result = 0;
        int i = 0;
        while (i < prices.size() - 1) {
            while (i < prices.size() - 1 && prices[i + 1] <= prices[i]) i++;
            valley = prices[i];
            while (i < prices.size() - 1 && prices[i + 1] >= prices[i]) i++;
            peak = prices[i];
            result += peak - valley;
        }
        return result;
    }
};
// brute force:
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] >= prices[i - 1]) {
                result += prices[i] - prices[i - 1];
            }
        }
        return result;
    }
};

// Q122 买卖股票3 at most 2 transactions
// simulation:
/*
cost1: the minimal cost of buying the stock in transaction #1. The minimal cost to acquire a stock would be the minimal price value that we have seen so far at each step.
gain1: the maximal profit of selling the stock in transaction #1. (Actually, at the end of the iteration, this value would be the answer for the leetcode121)
cost2: the minimal cost of buying the stock in transaction #2, while taking into account the profit gained from the previous transaction #1. (One can consider this as the cost of reinvestment. )
gain2: the maximal profit of selling the stock in transaction #2.

*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cost1 = INT_MAX, cost2 = INT_MAX;
        int gain1 = 0, gain2 = 0;
        for (int i = 0; i < prices.size(); i++) {
            cost1 = min(cost1, prices[i]);
            gain1 = max(gain1, prices[i] - cost1);
            cost2 = min(cost2, prices[i] - gain1);
            gain2 = max(gain2, prices[i] - cost2);
        }
        return gain2;
    }
};

// Q188 买卖股票4 at most k transactions
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k >= prices.size() / 2) { // if k >= n/2, then you can make maximum number of transactions
            int profit = 0;
            for (int i = 1; i < prices.size(); i++)
                if (prices[i] > prices[i - 1]) 
                    profit += prices[i] - prices[i - 1];
            return profit;
        }
        vector<int> buy(k + 1, INT_MAX);
        vector<int> sell(k + 1, 0);

        for (int price : prices) {
            for (int i = 1; i <= k; i++) {
                buy[i] = min(buy[i], price - sell[i - 1]);
                sell[i] = max(sell[i], price - buy[i]);
            }
        }
        return sell[k];
    }
};
