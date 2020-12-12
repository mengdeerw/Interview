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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // 找到新位置，插入新节点
        if (!root) return new TreeNode(val);
        // if (root->val == val)
        // BST中一般不会插入已存在的元素
        if (root->val < val)
            // 在root的右子树中继续寻找val并插入
            root->right = insertIntoBST(root->right, val);
        if (root->val > val)
            // 在root的左子树中继续寻找val并插入
            root->left = insertIntoBST(root->left, val);
        return root;
    }
};
