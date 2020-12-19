// METHOD-1: BFS
// Time complexity: O(N)
// Space complexity: O(N)
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int n = q.size();
            vector<int> nodes;
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                nodes.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            result.push_back(nodes);
        }
        return result;
    }
};

// METHOD-2: DFS
// Time complexity: O(N)
// Space complexity: O(N)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        dfs(root, 0, result);
        return result;
    }
    
    void dfs(TreeNode* root, int level, vector<vector<int>>& result) {
        if (!root) return;
        // create new vector for next level
        if (result.size() == level) {
            result.push_back(vector<int>());
        }
        result[level].push_back(root->val);
        dfs(root->left, level + 1, result);
        dfs(root->right, level + 1, result);
    }
};
