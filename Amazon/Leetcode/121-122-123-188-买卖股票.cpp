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
