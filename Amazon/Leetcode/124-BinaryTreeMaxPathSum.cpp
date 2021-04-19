/* So a way to solve this is that if I am at a node, I can choose a left or right subtree. but if I choose both this is the only subtree that will contain my maximum
1.I can choose to take up the left subtree or drop it.
2.I can either choose to take up the right subtree or drop it.
3.I check for a possibility whether if i were to take both left subtree and right subtree would that beat my current max_sum?
*/
// time complexity: O(N)
// space complexity: O(H) where H is the tree height
class Solution {
public:
    int max_sum = INT_MIN;
    
    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return max_sum;
    }
    
    int maxGain(TreeNode* root) {
        if (!root) return 0;
        int leftPathSum = max(maxGain(root->left), 0);
        int rightPathSum = max(maxGain(root->right), 0);
        max_sum = max(max_sum, root->val + leftPathSum + rightPathSum);
        return root->val + max(leftPathSum, rightPathSum);
    }
};
