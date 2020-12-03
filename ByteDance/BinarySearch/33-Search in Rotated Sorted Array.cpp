// Time complexity: O(logN)
// Space complexity: O(1)
// If a sorted array is shifted, if you take the middle, always one side will be in sorted order without rotation. 
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        
        while (start <= end) {
            int mid = start + (end - start)/2;
            if (nums[mid] == target) {
                return mid;
            }
            // left side is not rotated
            else if (nums[mid] >= nums[start]) { //consider case [3,1] with target 1               
                if (nums[start] <= target && target < nums[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
            else { // right side is not rotated
                if (nums[mid] < target && target <= nums[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }  
        }
        return -1;
    }
};
