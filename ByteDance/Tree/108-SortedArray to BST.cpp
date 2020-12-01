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

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return NULL;
        return buildBST(nums, 0, nums.size() - 1);
    }
    
    TreeNode* buildBST(vector<int>& nums, int left, int right) {
        if (left >= right) return NULL;
        int mid = (left + right)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildBST(nums, left, mid);
        root->right = buildBST(nums, mid+1, right);
        return root;
    }
};

// it is better to use iterator instead of index; no need to pass the array when calling recursion
class Solution {
public:
    using it = vector<int>::iterator;
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return NULL;
        return buildBST(nums.begin(), nums.end());
    }
    
    TreeNode* buildBST(it left, it right) {
        if (left >= right) return NULL;
        it mid = left + (right - left)/2;
        TreeNode *root = new TreeNode(*mid);
        root->left = buildBST(left, mid);
        root->right = buildBST(mid + 1, right);
        return root;
    }
};

