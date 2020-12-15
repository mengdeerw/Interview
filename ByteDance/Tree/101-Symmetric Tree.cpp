// every nodes' children must be mirrored, so we need a helper funtion to compare two treenode at a time
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
    
    bool isMirror(TreeNode* n1, TreeNode* n2) {
        if (!n1 && !n2) return true;
        if (!n1 || !n2) return false;
        return (n1->val == n2->val) && isMirror(n1->left, n2->right) && isMirror(n1->right, n2->left);
    }
};
