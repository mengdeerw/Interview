/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// leetcode-236
// DFS: the idea is to recursively check curr node, its left & right child to see if there is any nodes equal to target p and q;
/* 
1. traverse to the left leaf node and right leaf node;
2. if left && right all exists, means LCA is parent node;
3. if either left or right not exists, LCA is the existing node;
*/
// 2 cases:
// case1: left & right subtree all exists, then LCA is the parent node
// case2: either left or right subtree not exist, LCA is the existing node
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        if (root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left && right) return root;
        return left ? left : right;
    }
};

// leetcode 1644
// the difference from leetcode-236 is that we need to traverse the whole tree to see if both p and q are in the tree
class Solution {
public:
    bool pFound = false, qFound = false;
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {    
        TreeNode* result = LCA(root, p, q);
        return pFound && qFound ? result : NULL;
    }

private:
    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        
        TreeNode* left = LCA(root->left, p, q);
        TreeNode* right = LCA(root->right, p, q);
        
        // need to check this after looking into left and right subtrees becaue we need to confirm the entire tree
        if (root == p) {
            pFound = true;
            return root;
        }
        if (root == q) {
            qFound = true;
            return root;
        }
        
        if (left && right) return root;
        return left ? left : right;
    }
};
