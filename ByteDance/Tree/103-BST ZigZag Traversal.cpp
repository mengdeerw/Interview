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
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        
        int level = 0;
        while (!q.empty()) {
            level++;
            int n = q.size();
            vector<int> nodes;
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (level % 2 == 1) { // odd level
                    nodes.push_back(node->val);
                } else { // even level
                    nodes.insert(nodes.begin(), node->val);
                }
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            result.push_back(nodes);
        }
        return result;
    }
};
