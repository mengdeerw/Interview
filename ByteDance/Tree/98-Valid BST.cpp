// 正确做法：
// BST性质： 当前节点的值大于所有右子树节点的值 且 小于所有左子树节点的值
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validBST(root, NULL, NULL);
    }
    
    // 利用min，max限制当前node的值区间
    bool validBST(TreeNode* root, TreeNode* min, TreeNode* max) {
        if (!root) return true;
        if (min && root->val <= min->val) return false;
        if (max && root->val >= max->val) return false;
        return validBST(root->left, min, root) && validBST(root->right, root, max);
    }
};

// 错误做法：
class Solution {
public:
    /* 这种做法是错的，无法保证每个节点小于右子树的所有节点。比如：
       10
       /\
      5  15
         /\
        6 20 
    */
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        if (root->left && root->val <= root->left->val) return false;
        if (root->right && root->val >= root->right->val) return false;
        return isValidBST(root->left) && isValidBST(root->right);
    }
};
