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

// DFS + backtracking
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(root, path, sum, result);
        return result;
    }
    
    void dfs(TreeNode* root, vector<int>& path, int sum, vector<vector<int>>& result) {
        if (!root) return;
        // first update the path array, record all the nodes that have been traversed
        path.push_back(root->val);
        // if meet the leaf and hit target sum, push path to result
        if (!root->left && !root->right && root->val == sum) {
            result.push_back(path);
        }
        // 递归直至遇到leaf节点
        dfs(root->left, path, sum - root->val, result);
        dfs(root->right, path, sum - root->val, result);
        // 运行到此行说明已经遍历到leaf但还不满足path sum；这时需要回溯backtracking
        path.pop_back();
    }
};
