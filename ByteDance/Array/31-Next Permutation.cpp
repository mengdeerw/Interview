// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //step1: find an index i that all the elements after nums[i] is in descending order
        int i = nums.size() - 2;
        while (i >= 0 && nums[i + 1] <= nums[i]) {
            i--;
        }
        //step2: find an index j in the range of (i, nums.size()-1] that nums[j] > nums[i]
        // and swap nums[i] and nums[j]
        int j = nums.size() - 1;
        if (i >= 0) {
            while (j >= 0 && nums[j] <= nums[i]) {
                j--;
            }
            std::swap(nums[i], nums[j]);
        }
        //step 3: reverse all the elements after nums[i], so they'll in ascending order
        std::reverse(nums.begin() + i + 1, nums.end());
    }
};

// not using std library
// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //step1: find an index i that all the elements after nums[i] is in descending order
        int i = nums.size() - 2;
        while (i >= 0 && nums[i + 1] <= nums[i]) {
            i--;
        }
        //step2: find an index j in the range of (i, nums.size()-1] that nums[j] > nums[i]
        // and swap nums[i] and nums[j]
        int j = nums.size() - 1;
        if (i >= 0) {
            while (j >= 0 && nums[j] <= nums[i]) {
                j--;
            }
            swap(nums, i, j);
        }
        //step 3: reverse all the elements after nums[i], so they'll in ascending order
        reverse(nums, i + 1);
    }
    
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[j];
        nums[j] = nums[i];
        nums[i] = temp;
    }
    
    void reverse(vector<int>& nums, int start) {
        int i = start, j = nums.size() - 1;
        while (i < j) {
            swap(nums, i, j);
            i++;
            j--;
        }
    }
};
