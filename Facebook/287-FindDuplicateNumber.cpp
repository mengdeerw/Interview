// binary search
/* 
suppose the duplicate number is S, for the array values: [1, 3,...S,...S, S + 1,...n]
then there must be more than S numbers whose values are <= S:
1. For all the value that T >= S, there must be more than T number of values that <= T
2. For all the value that T < S, there must be less or equal than T number of values that <= T
*/
// time complexity: O(NlogN)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1, right = nums.size() - 1; // search range: [1, n]
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            int count = searchCount(nums, mid);
            if (count <= mid) {
                left = mid;
            } else {
                right = mid;
            }
        }
        // left + 1 == right
        if (searchCount(nums, left) <= left) return right;
        return left;
    }
private:
    // return how many numbers are less or equal than target
    int searchCount(vector<int>& nums, int target) {
        int count = 0;
        for (int num: nums) {
            if (num <= target) count++;
        }
        return count;
    }
};

// cycle detection
// time complexity: O(N)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() <= 1) return -1;
        int slow = nums[0];
        int fast = nums[nums[0]];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = 0;
        while (slow != fast) {
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
};
