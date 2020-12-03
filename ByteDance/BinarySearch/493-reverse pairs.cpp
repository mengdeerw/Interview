// time complexity: O(NlogN)
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
        
    }
    
    int mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return 0;
        int mid = (left + right) / 2;
        int count = mergeSort(nums, left, mid) 
                  + mergeSort(nums, mid + 1, right);
        int j = mid + 1;
        for (int i = left; i <= mid; i++) {
            while (j <= right && nums[i] > nums[j] * 2LL) 
                j++;
            count += j - (mid + 1); // how far j has traveled from start point
        }
        //merge and sort
        sort(nums.begin() + left, nums.begin() + right + 1);
        return count;
    }
};

