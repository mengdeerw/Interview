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
// inorder: root, left, right
// recursive
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }
    
    void inorder(TreeNode* root, vector<int>& result) {
        if (!root) return;
        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }
};

// BFS iteration (change node, not preferred)
// inorder: left, node, right
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        stack<TreeNode*> s;
        s.push(root);
        
        while (!s.empty()) {
            TreeNode* node = s.top();
            if (node->left) {
                s.push(node->left);
                node->left = NULL;
            } else {
                result.push_back(node->val);
                s.pop();
                if (node->right)
                    s.push(node->right);
            }
        }
        return result;
    }
};

// BFS iteration (not changing nodes, preferred)
// inorder: left, node, right
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        stack<TreeNode*> s;
        TreeNode* curr = root;
        
        while (!s.empty() || curr) {
            // continue until find the leftmost leaf node
            if (curr) {
                s.push(curr);
                curr = curr->left;
            } else { // else means no left child, then save current node and iterate to its right child
                TreeNode* node = s.top();
                result.push_back(node->val);
                s.pop();
                curr = node->right;
            }
        }
        return result;
    }
};

// preorder: root, left, right
// recursive
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorder(root, result);
        return result;
    }
    
    void preorder(TreeNode* root, vector<int>& result) {
        if (!root) return;
        result.push_back(root->val);
        preorder(root->left, result);
        preorder(root->right, result);
    }
};

// preorder: root, left, right
// stack iterative
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> treeStack;
        if (!root) return result;
        
        treeStack.push(root);
        while (!treeStack.empty()) {
            TreeNode* node = treeStack.top();
            treeStack.pop();
            result.push_back(node->val);
            if (node->right) treeStack.push(node->right);
            if (node->left) treeStack.push(node->left);
        }
        
        return result;
    }
};

// postorder: left, right, root
// recursive
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorder(root, result);
        return result;
    }
    
    void postorder(TreeNode* root, vector<int>& result) {
        if (!root) return;
        postorder(root->left, result);
        postorder(root->right, result);
        result.push_back(root->val);
    }
};

// BFS + iteration
// post order: left, right, node
// stack push order: node. right, left
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            result.push_back(node->val);
            if (node->left) s.push(node->left);
            if (node->right) s.push(node->right);
        }
        // 此时result中的顺序是node, right, left, 需反转
        reverse(result.begin(), result.end());
        return result;
    }
};
