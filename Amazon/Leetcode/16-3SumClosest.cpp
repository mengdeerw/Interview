class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int result = target;
        int minDiff = INT_MAX;
        
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == target) return target;
                
                int diff = abs(sum - target);
                if (diff < minDiff) {
                    minDiff = diff;
                    result = sum;
                }
                
                if (sum > target) r--;
                else l++;
            }
        }  
        return result;
    }
};
