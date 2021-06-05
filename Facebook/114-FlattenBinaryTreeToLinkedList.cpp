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
// iterative Morris Traversal
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        TreeNode* cur = root;
        while (cur) {
            //check if curr has a left child.
            if (cur->left) {
                TreeNode* pre = cur->left;
                // move to right most
                while (pre->right) {
                    pre = pre->right;
                }
                // reconnect
                pre->right = cur->right; // point curr's right subtree's next to correct position
                cur->right = cur->left; // point curr's next to its left subtree
                cur->left = NULL; // cut off left child
            }
            // point to the node on the right of curr.
            cur = cur->right;
        }
    }
};

class Solution {
public:
    void flatten(TreeNode* root) {
        preorder(root);
    }
    
private:
    // dfs: preorder traversal
    TreeNode* preorder(TreeNode* root) {
        if (!root) return NULL;
        
        // if current node is a leaf
        if (!root->left && !root->right) return root;
        
        // left subtree
        TreeNode* left = preorder(root->left);
        
        // right subtree
        TreeNode* right = preorder(root->right);
        
        // check if there is left subtree, need re-route the connection
        if (left) { // right child pointer points to the next node in the list and the left child pointer is always null
            left->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        // We need to return the "rightmost" node after we are
        // done wiring the new connections. 
        return right == NULL ? left : right; 
    }
};
