// leetcode 1465
// https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

// pay attention to large int number
class Solution {
public:
    int mod = 1e9 + 7;
    
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        return distance(h, horizontalCuts) % mod * distance(w, verticalCuts) % mod;
    }
    
    long long int distance(int limit, vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int curr = 0, last = 0;
        int max = INT_MIN;
        for (int num: arr) {
            curr = num - last;
            max = std::max(max, curr);
            last = num;
        }
        // check boundary
        max = std::max(max, limit - last);
        return max;
    }
};
