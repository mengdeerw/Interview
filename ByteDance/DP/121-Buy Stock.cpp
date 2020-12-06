// DP
// Time complexity: O(N)
// Space complexity: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, minPrice = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }
        return maxProfit;
    }
};

// DP
// Time complexity: O(N)
// Space complexity: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, minPrice = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            } else if (prices[i] - minPrice > maxProfit) {
                maxProfit = prices[i] - minPrice;
            }
        }
        return maxProfit;
    }
};

// Brute force
// Time complexity: O(N^2)
// Space complexity: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        
        for (int i = 0; i < prices.size() - 1; i++) {
            for (int j = i + 1; j < prices.size(); j++) {
                int profit = prices[j] - prices[i];
                maxProfit = max(maxProfit, profit);
            }
        }
        return maxProfit;
    }
};
