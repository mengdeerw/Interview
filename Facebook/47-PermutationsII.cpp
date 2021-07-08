// reuse the template from permuationsI
// plus using a hashmap
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> track;
        unordered_map<int, int> m;
        for (int num: nums) {
            m[num]++;
        }
        backtrack(nums, track, result, m);
        return result;
    }
private:
    void backtrack(vector<int>& nums, vector<int>& track, vector<vector<int>>& result, unordered_map<int, int>& m) {
        if (track.size() == nums.size()) {
            result.push_back(track);
            return;
        }
        for (auto& [num, count]: m) {
            if (count == 0) continue;
            // at this point, count of this num is not zero, means we can add it into track 
            track.push_back(num);
            m[num]--;
            backtrack(nums, track, result, m);
            // reset back
            track.pop_back();
            m[num]++;
        }
    }
};
