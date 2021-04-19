// recursive
// time complexity: O(N)
// space complexity: O(N) (recusive stack)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        // if one of the nodes has been found
        if (root == p || root == q) return root;
        // look for both nodes in both subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        // if p, q were found in different subtrees
        if (left && right) return root;
        // p, q in the same subtree
        return left ? left : right;
    }
};

// another version of recursive
class Solution {
public:
    TreeNode* lowestAncestor = NULL;
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL) return NULL;
    setLowestAncestor(root, p, q);
    return this->lowestAncestor;
}

private:
    int setLowestAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL || lowestAncestor) return 0;
    
    int r = (root == p || root == q) ? 1 : 0;
    int left = setLowestAncestor(root->left, p, q);
    int right = setLowestAncestor(root->right, p, q);
    
    if (r + left + right >= 2 && lowestAncestor == NULL) lowestAncestor = root;
    return r + left + right;
    }
};
