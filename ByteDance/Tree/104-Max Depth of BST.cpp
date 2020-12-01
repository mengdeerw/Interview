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

// METHOD-1: DFS + recursion
// traverse to the leaf nodes and then backtrack to their parents to calculate the depth
// Time Complextiy: O(N)
// Space Complexity: worst~O(N) Best:~O(logN) 
/* in the worst case, the tree is completely unbalanced, e.g. each node has only left child node, the recursion call would occur NN times (the height of the tree), therefore the storage to keep the call stack would be O(N). 
But in the best case (the tree is completely balanced), the height of the tree would be log(N). Therefore, the space complexity in this case would be O(log(N)).
*/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

// METHOD-2: BFS + iteration
// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int result = 0;
        if (!root) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        //level order traversal
        while (!q.empty()) {
            result++;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* t = q.front();
                q.pop();         
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
        return result;
    }
};
