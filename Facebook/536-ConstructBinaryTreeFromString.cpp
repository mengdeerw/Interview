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
// METHOD-1: inorder traversal
// using stack, whenever we meet ')' means we meet the leaf nodes, and we need to start popping the elements from the stack
class Solution {
public:
    TreeNode* str2tree(string s) {
        if (s.empty()) return NULL;
        stack<TreeNode*> st;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (c == '(') continue;
            if (isdigit(c) || c == '-') { // calculate current node value
                int val = 0;
                int sig = 1;
                if (c == '-') {
                    sig = -1;
                    i++;
                }
                while (i < s.length() && isdigit(s[i])) {
                    val = val * 10 + s[i] - '0';
                    i++;
                } // i will move to the next char by the end of while loop
                i--;
                st.push(new TreeNode(val * sig));
            } else if (c == ')'){
                TreeNode* cur = st.top(); 
                st.pop();
                TreeNode* parent = st.top();
                if (parent->left == NULL) {
                    parent->left = cur;
                } else {
                    parent->right = cur;
                }
            }
        }
        // root node will be remained in the stack by the end
        if (st.empty()) return NULL;
        return st.top();
    }
};

// METHOD-2: recursion
class Solution {
public:
    TreeNode* str2tree(string s) {
        if (s.empty()) return NULL;
        int i = 0;
        return buildTree(s, i);
    }
private:
    TreeNode* buildTree(string& s, int& i) {
        int start_pos = i;
        if (s[i] == '-') i++;
        while (isdigit(s[i])) i++;
        
        int val = stoi(s.substr(start_pos, i - start_pos));
        TreeNode* cur = new TreeNode(val);
        if (s[i] == '(') { // left node
            i++; // skip (
            cur->left = buildTree(s, i);
            i++; // skip )
        }
        
        if (s[i] == '(') {
            i++; // skip (
            cur->right = buildTree(s, i);
            i++; // skip )
        }
        return cur;
    }
};
