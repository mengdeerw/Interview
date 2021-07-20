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

// BFS queue
// keep track of the NULL node, if it is not the last node, then return false
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q;
        bool isNull = false;
        q.push(root);
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            if (cur == NULL) {
                isNull = true;
            } else {
                if (isNull) return false; // there is a NULL node before current node
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return true;
    }
};

// BFS version2
// BFS using vector
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        vector<TreeNode*> nodes;
        nodes.push_back(root);
        int i = 0;
        while (i < nodes.size() && nodes[i] != NULL) {
            nodes.push_back(nodes[i]->left);
            nodes.push_back(nodes[i]->right);
            i++;
        }
        while (i < nodes.size() && !nodes[i]) {
            i++;
        }
        return i == nodes.size();
    }
};
