// two pointers, from end
// Time: O(M + N)
// Space: O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1, p2 = n - 1, p = m + n - 1;
        
        while (p1 >= 0 && p2 >= 0) {
            nums1[p--] = nums1[p1] < nums2[p2] ? nums2[p2--] : nums1[p1--];
        }
        // add missing elements in nums2 (no need to add nums2 since merge result is in nums1)
        while (p2 >= 0) nums1[p--] = nums2[p2--];
    }
};

// two pointers, from start
// Time: O(M + N)
// Space: O(M)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums1_copy (nums1);
        int p1 = 0, p2 = 0, p = 0;
        
        while (p1 < m && p2 < n) {
            nums1[p++] = nums1_copy[p1] < nums2[p2] ? nums1_copy[p1++] : nums2[p2++];
        }
        
        while (p1 < m) nums1[p++] = nums1_copy[p1++];
        while (p2 < n) nums1[p++] = nums2[p2++];
    }
};
