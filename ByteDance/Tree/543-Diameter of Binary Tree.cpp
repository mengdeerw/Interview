// DFS
// Time complexity: O(N)
// Space complexity: O(H) where H is the height of the tree 
class Solution {
public:
    int ans;
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        ans = 0;
        LP(root);
        return ans;
    }
    
    int LP(TreeNode* root) {
        if (!root) return -1;
        int L = LP(root->left) + 1;
        int R = LP(root->right) + 1;
        ans = max(ans, L + R);
        return max(L, R);
    }
};
