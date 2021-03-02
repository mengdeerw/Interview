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

// BFS:
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes; // {x: {y: val}}
        queue<pair<TreeNode*, pair<int, int>>> q; // {TreeNode, {x, y}}
        q.push({root, {0, 0}});
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int x = p.second.first, y = p.second.second;
            nodes[x][y].insert(node->val);
            if (node->left) q.push({node->left, {x - 1, y + 1}});
            if (node->right) q.push({node->right, {x + 1, y + 1}});
        }
        
        vector<vector<int>> result;
        for (auto kv: nodes) {
            vector<int> col;
            for (auto kv2: kv.second) {
                for (int val: kv2.second) {
                    col.push_back(val);
                }
            }
            result.push_back(col);
        }
        return result;
    }
};

//DFS
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        dfs(root, 0, 0, nodes);
        vector<vector<int>> result;
        for (auto kv: nodes) {
            vector<int> col;
            for (auto kv2: kv.second) {
                for (int val: kv2.second) {
                    col.push_back(val);
                }
            }
            result.push_back(col);
        }
        return result;
    }
    
    void dfs(TreeNode* root, int x, int y, map<int, map<int, multiset<int>>>& nodes) {
        if (root != NULL) {
            nodes[x][y].insert(root->val);
            dfs(root->left, x - 1, y + 1, nodes);
            dfs(root->right, x + 1, y + 1, nodes);
        }
    }
};
