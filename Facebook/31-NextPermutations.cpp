/*
1.Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists, just reverse nums and done.
2.Find the largest index l > k such that nums[k] < nums[l].
3.Swap nums[k] and nums[l].
4.Reverse the sub-array nums[k + 1:].
*/
// time complexity: O(N)
// space complexity: O(1)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return;
        
        // find the largest index k that nums[k] < nums[k + 1]
        int k;
        for (k = n - 2; k >= 0; k--) {
            if (nums[k] < nums[k + 1]) break;
        }
        if (k < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        // find the largest index l that nums[k] < nums[l]
        int l;
        for (l = n - 1; l > k; l--) {
            if (nums[l] > nums[k]) break;
        }
        swap(nums[l], nums[k]);
        // reverse nums[k + 1: ]
        reverse(nums.begin() + k + 1, nums.end());
    }
};
