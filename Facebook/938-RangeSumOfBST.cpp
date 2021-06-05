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

// METHOD-1: using the BST properties
// case1: root->val < low, should go to the right subtree
// case2: root->val > high, should go to the left subtree
// case3: root->val ~[low, high]: we do a preorder traversal to find out the left & right boudary of the tree node; updating sum val during the traversal
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) return 0;
        int sum = 0;
        dfs(root, sum, low, high);
        return sum;
    }
private:
    void dfs(TreeNode* root, int& sum, int& low, int& high) {
        if (!root) return;
        if (root->val >= low && root->val <= high) {
            sum += root->val;
            dfs(root->left, sum, low, high);
            dfs(root->right, sum, low, high);
        }
        if (root->val < low) dfs(root->right, sum, low, high);
        if (root->val > high) dfs(root->left, sum, low, high);
    }
};

// METHOD-2: general inorder traversal for all binary tree
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) return 0;
        int sum = 0;
        inorder(root, sum, low, high);
        return sum;
    }
private:
    void inorder(TreeNode* root, int& sum, int& low, int& high) {
        if (!root) return;
        inorder(root->left, sum, low, high);
        if (root->val >= low && root->val <= high) {
            sum += root->val;
        }
        inorder(root->right, sum, low, high);
    }
};
