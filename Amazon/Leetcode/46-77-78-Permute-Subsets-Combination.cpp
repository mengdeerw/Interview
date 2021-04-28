// 46-Permutation https://leetcode.com/problems/permutations/
/*
                      []
      [1]            [2]           [3]  
  [1 2] [1 3]    [2 1] [2 3]      [3 1] [3 2]
[1 2 3] [1 3 2]  [2 1 3][2 3 1]  [3 1 2] [3 2 1]
*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> track;
        backtrack(nums, track, result);
        return result;
    }
    
    void backtrack(vector<int>& nums, vector<int>& track, vector<vector<int>>& result) {
        if (track.size() == nums.size()) {
            result.push_back(track);
            return;
        }
        for (int num: nums) {
            auto it = find(track.begin(), track.end(), num);
            if (it != track.end()) continue;
            track.push_back(num);
            backtrack(nums, track, result);
            track.pop_back();
        }
    }
};

// 77-Combination: https://leetcode.com/problems/combinations/
/*
                        []
        [1]          [2]         [3]   [4]
[1 2] [1 3] [1 4]  [2 3] [2 4]  [3 4]
*/
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> track;
        backtrack(n, k, 1, result, track);
        return result;
    }
    
    void backtrack(int n, int k, int start, vector<vector<int>>& result, vector<int>& track) {
        if (k == track.size()) {
            result.push_back(track);
            return;
        }
        else {
            for (int i = start; i <= n; i++) {
                track.push_back(i);
                backtrack(n, k, i + 1, result, track);
                track.pop_back();
            }
        }
    }
};

// 78-Subsets https://leetcode.com/problems/subsets/
/*
              []
    [1]       [2]      [3]  
[1 2] [1 3]  [2 3]  
[1 2 3]
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> track;
        backtrack(nums, 0, track, result);
        return result;
    }
    
    void backtrack(vector<int>& nums, int start, vector<int>& track, vector<vector<int>>& result) {
        result.push_back(track);
        for (int i = start; i < nums.size(); i++) {
            track.push_back(nums[i]);
            backtrack(nums, i + 1, track, result);
            track.pop_back();
        }
    }
};
