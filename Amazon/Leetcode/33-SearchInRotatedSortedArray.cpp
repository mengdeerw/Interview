// time complexity: O(logN)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (target == nums[mid]) return mid;
            if (nums[start] <= nums[mid]) //  pivot in right side
            {
                if (target >= nums[start] && target < nums[mid]) end = mid - 1;
                else start = mid + 1;
            } else // pivot in left side
            {
                if (target > nums[mid] && target <= nums[end]) start = mid + 1;
                else end = mid - 1;
            }
        }
        return -1;
    }
};
