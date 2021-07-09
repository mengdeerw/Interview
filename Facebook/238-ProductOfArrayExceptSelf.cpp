// left and right product lists using the same result array
// time complexity: O(N)
// space complexity: O(N)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 1), right(n, 1);
        for (int i = 1; i < n; i++) {
            left[i] = left[i - 1] * nums[i - 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            right[i] = right[i + 1] * nums[i + 1];
        }
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            result[i] = left[i] * right[i];
        }
        return result;
    }
};

/*
for [a, b, c, d]
the answer should be: [bcd, acd, abd, abc]
which is equivalent:  [|1|*(bcd), |a|*(cd), |ab|*(d), |abc|*(1)]
1st time scan: left->right left= [1, 1*a, 1*a*b, 1*a*b*c]
2nd time scan: right->left right [1*b*c*d, 1*c*d, 1*d, 1]
result = left * right
scan two times: 1st time with |x| from left to right, 2nd time with (x) from right to left
*/
