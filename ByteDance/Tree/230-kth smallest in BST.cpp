/*
Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
*/
/*If we could add a count field in the BST node class, it will take O(n) time when we calculate the count value for the whole tree, 
but after that, it will take O(logn) time when insert/delete a node or calculate the kth smallest element.*/
class Node {
public:
    int val, size;
    Node *left, *right;
    Node(int v) : val(v), size(1), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        Node* node = addSize(root);
        return find(node, k);
    }
private:
    Node* addSize(TreeNode* root) {
        if (!root) {
            return NULL;
        }
        Node* node = new Node(root -> val);
        node -> left = addSize(root -> left);
        node -> right = addSize(root -> right);
        if (node -> left) {
            node -> size += node -> left -> size;
        }
        if (node -> right) {
            node -> size += node -> right -> size;
        }
        return node;
    }
    
    int find(Node* node, int k) {
        if (node -> left) {
            if (node -> left -> size >= k) {
                return find(node -> left, k);
            }
            if (node -> left -> size == k - 1) {
                return node -> val;
            }
            return find(node -> right, k - node -> left -> size - 1);
        }
        if (k == 1) {
            return node -> val;
        }
        return find(node -> right, k - 1);
    }
};
