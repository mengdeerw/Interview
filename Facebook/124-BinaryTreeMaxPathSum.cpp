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

// dfs
// at a certain node, make choice to get the maxGain maxgain = node->val + max(left, right)
// Max_leftSum = max(0, maxgain(left))
// Max_rightSum = max(0, maxgain(right))
// max_sum = node->val + Max_leftSum + Max_rightSum to form a complete path
class Solution {
public:
    int max_sum = INT_MIN;
    
    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return max_sum;
    }
    
private:
    // return the max gain for a node to root path
    int maxGain(TreeNode* root) {
        if (!root) return 0;
        int max_l_gain = max(0, maxGain(root->left));
        int max_r_gain = max(0, maxGain(root->right));
        // update max_sum
        max_sum = max(max_sum, root->val + max_l_gain + max_r_gain);
        return root->val + max(max_l_gain, max_r_gain);
    }
};
// need to pay attention to corner case: if there is negative value node in the tree
