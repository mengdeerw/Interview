
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

// METHOD-1: recursive: using a vector to store values
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> vals;
        inorder(vals, root);
        
        TreeNode* dummy = new TreeNode(0);
        TreeNode* curr = dummy;
        for (int val: vals) {
            curr->right = new TreeNode(val);
            curr = curr->right;
        }
        return dummy->right;
    }
    
    void inorder(vector<int>& vals, TreeNode* root) {
        if (!root) return;
        inorder(vals, root->left);
        vals.push_back(root->val);
        inorder(vals, root->right);
    }
};

// METHOD-2: recursive inorder traversal
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(0);
        TreeNode* curr = dummy;
        inorder(curr, root);
        return dummy->right;
    }
    
    void inorder(TreeNode*& curr, TreeNode* root) {
        if (!root) return;
        inorder(curr, root->left);
        root->left = NULL;
        curr->right = root;
        curr = curr->right;
        inorder(curr, root->right);
    }
};
