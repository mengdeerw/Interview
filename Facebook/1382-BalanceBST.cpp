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
// 要注意BST的性质，原数是BST所以如果我们对其进行inorder traversal拿到的数组一定是有序的
class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return buildBST(0, sorted.size() - 1);
    }
private:
    void inorder(TreeNode* root) {
        if (!root) return;
        // left
        inorder(root->left);
        // root
        sorted.push_back(root);
        // right
        inorder(root->right);
    }
    
    TreeNode* buildBST(int start, int end) {
        if (start > end) return NULL;
        int mid = start + (end - start) / 2;
        TreeNode *root = sorted[mid];
        root->left = buildBST(start, mid - 1);
        root->right = buildBST(mid + 1, end);
        return root;
    }
    
    vector<TreeNode*> sorted;
};
