// METHOD-1: swap
// Time complexity: O(n*n!) Note that there are n! permutations and it requires O(n) time to print a a permutation.
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(nums, 0, result);
        return result;
    }
    
    // permute num[begin..end]
    // invariant: num[0..begin-1] have been fixed/permuted
    void backtrack(vector<int>& nums, int begin, vector<vector<int>>& result) {
        if (begin >= nums.size()) {
            result.push_back(nums);
            return;
        }
        
        for (int i = begin; i < nums.size(); i++) {
            swap(nums[begin], nums[i]);
            backtrack(nums, begin + 1, result);
            swap(nums[begin], nums[i]);
        }
    }
};

// METHOD-2: recursion
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
        
        for (int i = 0; i < nums.size(); i++) {
            auto it = find(track.begin(), track.end(), nums[i]);
            if (it != track.end()) continue;
            track.push_back(nums[i]);
            backtrack(nums, track, result);
            track.pop_back();
        }
    }
};
// METHOD-2: another version
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> track;
        vector<bool> visited (nums.size(), false);
        backtrack(nums, track, result, visited);
        return result;
    }
    
    void backtrack(vector<int>& nums, vector<int>& track, vector<vector<int>>& result, vector<bool>& visited) {
        if (track.size() == nums.size()) {
            result.push_back(track);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) continue;
            visited[i] = true;
            track.push_back(nums[i]);
            backtrack(nums, track, result, visited);
            track.pop_back();
            visited[i] = false;
        }
    }
};

// METHOD-3: iterative + insert numbers
