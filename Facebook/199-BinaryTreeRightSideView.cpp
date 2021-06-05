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

// BFS: level order traversal
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            for (int i = q.size() - 1; i >= 0; i--) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                if (i == 0) result.push_back(node->val);
            }
        }
        return result;
    }
};

// DFS: modified preorder traversal
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        dfs(root, result, 0);
        return result;
    }
    
private:
    void dfs(TreeNode* root, vector<int>& result, int level) {
        if (!root) return;
        if (level == result.size()) result.push_back(root->val); // this ensures that we reach the right most node of this level
        dfs(root->right, result, level + 1);
        dfs(root->left, result, level + 1);
    }
};
