//      A
//     / \
//     B   C
//    / \  /
//    D E  F

struct Node {
    Node* left;
    Node* right;
}

Node* first = NULL, last = NULL;

Node* convertTreeToList(Node* root) 
{
    inorder(root);
    return first;
}

tuple<Node*, Node*> inorder(Node* root) {
    if (!root) return;
    [left_first, left_last] = inorder(root->left);
    [right_first, right_last] = inorder(root->right);
    root->left = left_last;
    left_last->right = root;
    root->right = right_first;
    right_first->left = root;    
    return [left_first, right_last];
}
// in-order traversal, D-B-E-A-C
// tree -> doubly-linked list
// D->right == B
// B->left == D

// st:  
// CUR 
// last = A
//d->b->E->a->c
Node* convertTreeToList(Node* root) {
    if (!root) return NULL;

    stack<Node*> st;
    Node* cur = root;
    Node* head = NULL;
    Node* last = NULL;
    while (cur || !st.empty()) {
        // go to left most
        while (cur) {
            st.push(cur);
            cur = cur->left;
        }
        // connect
        if (!st.empty()) {
            Node* top = st.top();
            if (!head) head = top;
            st.pop();
        }
        if (!last) last = head;
        else {
            last->right = top;
            top->left = last;
            last = top; // update last node
        }
        // go to right child
        if (cur->right) cur = cur->right;
    }
    return head;
}
