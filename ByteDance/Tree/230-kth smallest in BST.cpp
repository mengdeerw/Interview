// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// METHOD-1: traversal + min heap
class Solution {
public:
    //auto cmp = [](auto const& a, auto const& b){
    struct cmp {
        bool operator()(int a, int b) {
            return a > b;
        }
    };
    
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int, vector<int>, cmp> pq;

        inorder(root, pq);
        // k = 1 是第一大的
        k--;
        while (k) {
            pq.pop();
            k--;
        }
        return pq.top();
    }
    
    void inorder(TreeNode* root, priority_queue<int, vector<int>, cmp>& pq) {
        if (!root) return;
        inorder(root->left, pq);
        pq.push(root->val);
        inorder(root->right, pq);
    }
};

/*
Try the left subtree first. If that made k zero, then its answer is the overall answer and we return it right away. 
Otherwise, decrease k for the current node, and if that made k zero, then we return the current node's value right away. 
Otherwise try the right subtree and return whatever comes back from there.
*/

// METHOD-2: 用BST的特点，只需维护一个stack即可，不需要heap
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode *curr = root;
        while (!s.empty() || curr) {
            if (curr) {
                s.push(curr);
                curr = curr->left;
            } else {
                curr = s.top();
                s.pop();
                k--;
                if (k == 0) return curr->val;
                curr = curr->right;
            }
        }
        return -1;
    }
};

//METHOD-3: recursive inorder traversal 
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> nodes;
        inorder(root, nodes);
        return nodes[k - 1];
    }
    
    void inorder(TreeNode* root, vector<int>& nodes) {
        if (!root) return;
        inorder(root->left, nodes);
        nodes.push_back(root->val);
        inorder(root->right, nodes);
    }
};

// METHOD-4: DFS: 算出每个节点所有比其小的节点个数
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = countNodes(root->left);
        if (k - 1 < count) return kthSmallest(root->left, k);
        if (k - 1 > count) return kthSmallest(root->right, k-count-1);
        return root->val; //寻找k-1等于count的节点
    }
    
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

/*
Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? 
How would you optimize the kthSmallest routine?
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
