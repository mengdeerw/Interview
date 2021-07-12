/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

// METHOD-1: iterative traversal
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) return NULL;
        Node* cur = root;
        Node* first = NULL;
        Node* last = NULL;
        stack<Node*> st;
        
        while (cur || !st.empty()) {
            // go to leftmost node
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            if (!first) { // initialize
                first = cur;
                last = cur;
            } else {
                last->right = cur;
                cur->left = last;
                last = cur;
            }
            // go to next right node
            cur = cur->right;
        }
        // connect first and last node
        last->right = first;
        first->left = last;
        return first;
    }
};

// METHOD-2: recursion
class Solution {
public:
    Node* first = NULL;
    Node* last = NULL;
    
    Node* treeToDoublyList(Node* root) {
        if (!root) return NULL;
        inorder(root);
        last->right = first;
        first->left = last;
        return first;
    }
    
private:
    void inorder(Node* root) {
        if (!root) return;
        // left
        inorder(root->left);
        // root
        if (!first) {
            first = root;
            last = root;
        } else {
            last->right = root;
            root->left = last;
            last = root; // don't forget to update last node
        }
        // right
        inorder(root->right);
    }
};
