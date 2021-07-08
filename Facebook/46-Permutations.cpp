class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> track;
        backtrack(nums, track, result);
        return result;
    }
private:
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

/*
                      []
      [1]            [2]           [3]  
  [1 2] [1 3]    [2 1] [2 3]      [3 1] [3 2]
[1 2 3] [1 3 2]  [2 1 3][2 3 1]  [3 1 2] [3 2 1]
