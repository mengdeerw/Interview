class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        
        map<int, vector<int>> nodes;
        queue<pair<TreeNode*, int>> q; // each node with its horizontal distrance from root
        q.push({root, 0});
        
        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int dis = q.front().second;
            q.pop();
            
            nodes[dis].push_back(node->val);
            if (node->left) q.push({node->left, dis - 1});
            if (node->right) q.push({node->right, dis + 1});
        }
        
        for (auto kv: nodes) {
            result.push_back(kv.second);
        }
        return result;
    }
};
