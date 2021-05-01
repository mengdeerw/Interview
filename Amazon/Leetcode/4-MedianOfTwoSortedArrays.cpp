// binary search
// Time complexity: O(log(min(n1, n2)))
/*
A0, A1, A2.....A(n1-1)
B0, B1, B2.....B(n2-1)
assume we need to take m1 elements from Array A and m2 elements from ArrayB
so m1 + m2 = K = (n1 + n2 + 1) / 2
median must be from A(m1-1), B(m2-1), A(m1), B(m2)
use binary search to find m1 (based on A[m1] < B[m2-1])

左中位数C[k - 1] = max(A[m1-1], B[m2-1])
右中位数C[k] = min(A[m1], B[m2])
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int n1 = nums1.size();
        const int n2 = nums2.size();
        // make sure n1 always <= n2
        if (n1 > n2) return findMedianSortedArrays(nums2, nums1);
        
        const int k = (n1 + n2 + 1) / 2;
        int l = 0, r = n1 - 1;
        while (l <= r) {
            int m1 = (l + r) /2;
            int m2 = k - m1;
            if (nums1[m1] < nums2[m2 - 1]) l = m1 + 1;
            else r = m1 - 1;
        }
        
        int m1 = l, m2 = k - m1;
        int c1 = max(m1 <= 0 ? INT_MIN : nums1[m1 - 1],
                     m2 <= 0 ? INT_MIN : nums2[m2 - 1]);
        int c2 = min(m1 >= n1 ? INT_MAX : nums1[m1],
                     m2 >= n2 ? INT_MAX : nums2[m2]);
        if ((n1 + n2) % 2 == 1) return c1;
        else return (c1 + c2) * 0.5;
    }
};
