/*
for [a, b, c, d]
the answer should be: [bcd, acd, abd, abc]
which is equivalent:  [(bcd), |a|*(cd), |ab|*(d), |abc|]
scan two times: 1st time with |x| from left to right, 2nd time with (x) from right to left
*/
// left and right product lists
// time complexity: O(N)
// space complexity: O(N)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);
        // from left to right
        for (int i = 1; i < n; i++) {
            result[i] = result[i - 1] * nums[i - 1];
        }
        // from right to left
        int R = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= R;
            R *= nums[i];
        }
        return result;
    }
};

// left and right product lists using the same result array
// time complexity: O(N)
// space complexity: O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);
        // from left to right
        for (int i = 1; i < n; i++) {
            result[i] = result[i - 1] * nums[i - 1];
        }
        // from right to left
        int R = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= R;
            R *= nums[i];
        }
        return result;
    }
};
