// METHOD-1: bitmask
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int p = 1 << n;
        vector<vector<int>> result (p);
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) {
                    result[i].push_back(nums[j]);
                }
            }
        }
        return result;
    }
};

// METHOD-2: backtrack
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> sub;
        backtrack(nums, 0, sub, result);
        return result;
    }
    
    void backtrack(vector<int>& nums, int i, vector<int>& sub, vector<vector<int>>& result) {
        result.push_back(sub);
        for (int j = i; j < nums.size(); j++) {
            sub.push_back(nums[j]);
            backtrack(nums, j + 1, sub, result);
            sub.pop_back();
        }
    }
};

// METHOD-3: iterative
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result = {{}};
        for (int num: nums) {
            int n = result.size();
            for (int i = 0; i < n; i++) {
                result.push_back(result[i]);
                result.back().push_back(num);
            }
        }
        return result;
    }
};
