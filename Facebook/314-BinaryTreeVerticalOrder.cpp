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

// while traversing the tree in level order, update the map to record the y-axis of each node
// then traverse the map will let us know the vertial order of the tree
// p.s. we need a map instead of unordered_map because vertical order needs to be started from the very left y-axis
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<int>> nodes; // {y-axis: {node values}}
        queue<pair<TreeNode*, int>> q;
        vector<vector<int>> result;
        if (!root) return result;
        // level order traversal
        q.push({root, 0}); // set root as y = 0
        while (!q.empty()) {
            TreeNode* cur = q.front().first;
            int dis = q.front().second;
            q.pop();
            
            // update map
            nodes[dis].push_back(cur->val);
            if (cur->left) q.push({cur->left, dis - 1});
            if (cur->right) q.push({cur->right, dis + 1});
        }
        for (auto& [dis, vals]: nodes) {
            result.push_back(vals);
        }
        return result;
    }
};
