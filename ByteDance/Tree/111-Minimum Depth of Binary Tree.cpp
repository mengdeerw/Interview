// BFS
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        
        int depth = 1;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (!curr->left && !curr->right) return depth;
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            depth++;
        }
        return depth;
    }
};
