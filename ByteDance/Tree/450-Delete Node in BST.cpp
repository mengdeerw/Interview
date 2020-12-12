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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;
        // search and find the node whose value equals key
        if (root->val == key) {
            // case 1: key node is the leaf node
            if (!root->left && !root->right) return NULL;
            // case 2: key node has only one child
            if (!root->left) return root->right;
            if (!root->right) return root->left;
            // case3: key node has two children
            /*两种办法：
            1. 置换指针，将右子树最小值节点指向当前节点（链表操作，不会改动内部数据）
            2. 直接交换节点值（一般不会这样修改节点内部的值以交换节点，因为具体应用中，val域可能很大，修改会很耗时）
            */
            TreeNode *minNode = getMin(root->right);
            root->val = minNode->val;
            root->right = deleteNode(root->right, minNode->val);
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
    
    TreeNode* getMin(TreeNode* node) {
        while (node->left) node = node->left;
        return node;
    }
};
