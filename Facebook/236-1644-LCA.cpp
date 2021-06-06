/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// LEETCODE 236: LCAi
// DFS: the idea is to recursively check curr node, its left & right child to see if there is any nodes equal to target p and q;
/* 
1. traverse to the left leaf node and right leaf node;
2. if left && right all exists, means LCA is parent node;
3. if either left or right not exists, LCA is the existing node;
*/
// 2 cases:
// case1: left & right subtree all exists, then LCA is the parent node
// case2: either left or right subtree not exist, LCA is the existing node
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        if (root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left && right) return root;
        return left ? left : right;
    }
};

// LEETCODE 1644: LCAii
// the difference from leetcode-236 is that we need to traverse the whole tree to see if both p and q are in the tree
class Solution {
public:
    bool pFound = false, qFound = false;
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {    
        TreeNode* result = LCA(root, p, q);
        return pFound && qFound ? result : NULL;
    }

private:
    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        
        TreeNode* left = LCA(root->left, p, q);
        TreeNode* right = LCA(root->right, p, q);
        
        // need to check this after looking into left and right subtrees becaue we need to confirm the entire tree
        if (root == p) {
            pFound = true;
            return root;
        }
        if (root == q) {
            qFound = true;
            return root;
        }
        
        if (left && right) return root;
        return left ? left : right;
    }
};

// LEETCODE 1650: LCAiii
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

/* METHOD-1: 
1. Calculate the depth of both nodes
2. move the nodes to their parents and update the depth until the depths are the same
3. while parent nodes are not pointing to the same node, contiuously visit their parents until they are the same.
*/
// time complexity: O(h) where h is the height of the treee
class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        int p_depth = depth(p), q_depth = depth(q);
        
        while (p_depth > q_depth) {
            p_depth--;
            p = p->parent;
        }
        
        while (q_depth > p_depth) {
            q_depth--;
            q = q->parent;
        }
        // at this point, q_depth == p_depth, two nodes are at the same level;
        while (p != q) {
            p = p->parent;
            q = q->parent;
        }
        return p;
    }
    
    int depth(Node* node) {
        int depth = 0;
        while (node) {
            node = node->parent;
            depth++;
        }
        return depth;
    }
};

// METHOD2: 
//It is just a variation of Intersection of LinkedList!
// Time complexity: O(h1 + h2)
class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node* pp = p;
        Node* qq = q;
        while (pp != qq) {
            pp = (pp == NULL) ? q : pp->parent;
            qq = (qq == NULL) ? p : qq->parent;
        }
        return pp;
    }
};
