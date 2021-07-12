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

/*
1. Calculate the depth of both nodes
2. move the nodes to their parents and update the depth until the depths are the same
3. while parent nodes are not pointing to the same node, contiuously visit their parents until they are the same.
*/
// time complexity: O(h) where h is the height of the treee
class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        int p_depth = depth(p);
        int q_depth = depth(q);
        
        // p is lower
        while (p_depth > q_depth) {
            p_depth--;
            p = p->parent;
        }        
        // q is lower
        while (q_depth > p_depth) {
            q_depth--;
            q = q->parent;
        }
        // p & q are at the same level
        while (p != q) {
            p = p->parent;
            q = q->parent;
        }
        return p;
    }
    
private:
    int depth(Node* node) {
        int depth = 0;
        while (node) {
            node = node->parent;
            depth++;
        }
        return depth;
    }
};

// METHOD-2:
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
