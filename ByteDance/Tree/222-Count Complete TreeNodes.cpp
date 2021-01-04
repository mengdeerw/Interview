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

// Time complexity: O(logNlogN)
class Solution {
public:
    int countNodes(TreeNode* root) {
        TreeNode *l = root, *r = root;
        int hl = 0, hr = 0; //左右子树的高度
        while (l) {
            l = l->left;
            hl++;
        }
        while (r) {
            r = r->right;
            hr++;
        }
        
        //左右子树高度相同，即满二叉树
        if (hl == hr) {
            return (int)pow(2, hl) - 1;
        }
        //左右子树高度不同，按普通二叉树逻辑计算
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
