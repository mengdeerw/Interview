/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// METHOD-1: recursion + linear search
// time complexity: O(N)
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        vector<int> nums;
        inorder(root, nums);
        int result = nums[0];
        for (int num: nums) {
            result = (abs(num - target) < abs(result - target)) ? num : result;
        }
        return result;
    }
private:
    void inorder(TreeNode* root, vector<int>& nums) {
        if (!root) return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
};

// METHOD-2: binary search
// time complexity: O(H) where H is the height of the tree
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int closest = root->val, cur = 0;
        while (root) {
            cur = root->val;
            closest = abs(cur - target) < abs(closest - target) ? cur : closest;
            root = target < root->val ? root->left : root->right;
        }
        return closest;
    }
};
