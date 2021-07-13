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
// METHOD-1: BFS
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes; // use multiset to deal with nodes having duplicate values.
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while (!q.empty()) {
            TreeNode* cur = q.front().first;
            int x = q.front().second.first, y = q.front().second.second;
            q.pop();
            nodes[x][y].insert(cur->val);
            if (cur->left) {
                q.push({cur->left, {x - 1, y + 1}});
            }
            if (cur->right) {
                q.push({cur->right, {x + 1, y + 1}});
            }
        }
        vector<vector<int>> result;
        for (auto& [x, y_vals]: nodes) {
            vector<int> cols;
            for (auto& [y, vals]: y_vals) {
                cols.insert(cols.end(), vals.begin(), vals.end()); // insert set into vector
            }
            result.push_back(cols);
        }
        return result;
    }
};

// METHOD-2: DFS
class Solution {
public:
    map<int, map<int, multiset<int>>> nodes;
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        vector<vector<int>> result;
        for (auto& [x, y_vals]: nodes) {
            vector<int> cols;
            for (auto& [y, vals]: y_vals) {
                cols.insert(cols.end(), vals.begin(), vals.end());
            }
            result.push_back(cols);
        }
        return result;
    }
    
    void dfs(TreeNode* root, int x, int y) {
        if (!root) return;
        nodes[x][y].insert(root->val);
        dfs(root->left, x - 1, y + 1);
        dfs(root->right, x + 1, y + 1);
    }
};
