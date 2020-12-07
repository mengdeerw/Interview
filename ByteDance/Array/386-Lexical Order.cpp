class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result (n);
        int curr = 1;
        for (int i = 0; i < n; i++) {
            result[i] = curr;
            if (curr * 10 <= n) {
                curr *= 10;
            } else {
                if (curr >= n) curr /= 10;
                curr++;
                while (curr % 10 == 0) curr /= 10; // consider if curr == 9999-> curr+1=10000, need to remove all the '0' after '1'
            }
        }
        return result;
    }
};
