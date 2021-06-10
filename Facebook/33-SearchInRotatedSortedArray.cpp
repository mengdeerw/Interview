// for a certain rotated sorted array, mid position must make either side as sorted 
// so the key idea is to find out whether target is in sorted range or not;
// if not, just switch to the unsorted range, and find out the pivot again

// version 1
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        while (start <= end) { // range can be shrink to [1], so just need to return -1 at the end
            int mid = start + (end - start) / 2; // for range with double number of elements, mid will located at lower side
            if (nums[mid] == target) return mid;
            else if (nums[mid] >= nums[start]) { // left side must be sorted, pivot is in right side
                // check whether target is in sorted side or not
                if (target >= nums[start] && target < nums[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else { // right side must be sorted
                if (target > nums[mid] && target <= nums[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1; 
    }
};

// version 2
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        while (start < end) { // out of the while loop, need to judge separately when start == end 
            int mid = start + (end - start) / 2; // pay attention that for even number array, mid position will be in left side
            if (nums[mid] == target) return mid;
            else if (nums[mid] >= nums[start]) { // left side sorted
                if (target >= nums[start] && target < nums[mid]) {
                    end = mid - 1; // end = mid will also work
                } else {
                    start = mid + 1;
                }
            } else { // right side sorted
                if (nums[mid] < target && target <= nums[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1; // end = mid will also work
                }
            }
        }
        // now start == end
        return nums[start] == target ? start : -1;
    }
};
