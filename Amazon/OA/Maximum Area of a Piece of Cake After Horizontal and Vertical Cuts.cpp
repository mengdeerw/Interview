// leetcode 1465
// https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

// time complexity: O(NlogN)
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

// another version
class Solution {
public:
  int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
    constexpr int kMod = 1e9 + 7;
    sort(begin(verticalCuts), end(verticalCuts));
    sort(begin(horizontalCuts), end(horizontalCuts));
    int mx = max(verticalCuts[0], w - verticalCuts.back());
    int my = max(horizontalCuts[0], h - horizontalCuts.back());
    for (int i = 1; i < verticalCuts.size(); ++i)
      mx = max(mx, verticalCuts[i] - verticalCuts[i - 1]);
    for (int i = 1; i < horizontalCuts.size(); ++i)
      my = max(my, horizontalCuts[i] - horizontalCuts[i - 1]);               
    return static_cast<long>(mx) * my % kMod;
  }
};
