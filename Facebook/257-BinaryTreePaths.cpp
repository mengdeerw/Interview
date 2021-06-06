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

// METHOD-1: dfs
// traverse until reach the leaf node
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (!root) return result;
        dfs(root, result, "");
        return result;
    }
    
    void dfs(TreeNode* root, vector<string>& result, string path) {
        if (!root) return;
        if (!root->left && !root->right) {
            path += to_string(root->val);
            result.push_back(path);
        }
        // otherwise, append current node val to path string
        path += to_string(root->val) + "->";
        dfs(root->left, result, path); 
        dfs(root->right, result, path);
    }
};

// METHOD_2: iterative
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (!root) return result;
        stack<pair<TreeNode*, string>> st;
        st.push({root, to_string(root->val)});
        while (!st.empty()) {
            auto pair = st.top();
            st.pop();
            TreeNode* node = pair.first;
            string path = pair.second;
            if (!node->left && !node->right) {
                result.push_back(path);
            }
            if (node->left) {
                st.push({node->left, path + "->" + to_string(node->left->val)});
            }
            if (node->right) {
                st.push({node->right, path + "->" + to_string(node->right->val)});
            }
        }
        return result;
    }
};
