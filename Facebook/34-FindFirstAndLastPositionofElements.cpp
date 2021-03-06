// 模板一： while (left <= right)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {;
        int first = findFirst(nums, target);
        int last = findLast(nums, target);
        return {first, last};
    }

private:
    int findFirst(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        int left = 0, right = nums.size() - 1; // [l, r]
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) { // shrink right boundary
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        // left = right + 1 check left
        if (left >= nums.size() || nums[left] != target) return -1;
        return left;
    }
    
    int findLast(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) { // shrink left boundary
                left = mid + 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        // left = right + 1; check right
        if (right < 0 || nums[right] != target) return -1;
        return right;
    }
};

// 模板二： while (left + 1 < right)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {;
        int first = findFirst(nums, target);
        int last = findLast(nums, target);
        return {first, last};
    }

private:
    int findFirst(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        int left = 0, right = nums.size() - 1; // [l, r]
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) { // shrink right boundary
                right = mid;
            } else if (nums[mid] < target) {
                left = mid;
            } else {
                right = mid;
            }
        }
        // left + 1 = right
        if (nums[left] != target && nums[right] != target) return -1;
        if (nums[left] == target) return left;
        return right;
    }
    
    int findLast(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        int left = 0, right = nums.size() - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) { // shrink left boundary
                left = mid;
            } else if (nums[mid] < target) {
                left = mid;
            } else {
                right = mid;
            }
        }
        // left + 1 = right
        if (nums[left] != target && nums[right] != target) return -1;
        if (nums[right] == target) return right;
        return left;
    }
};
