/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

// METHOD-1: Distance with Depth
// The depth of a node is the length of the path to the root node.
// diameter = max(diameter, max(depth_child1 + depth_child2, .....))
// we use a variable "max_cur_depth" to record the current max depth of all the children;
// when we traverse the all the children node, we keep updating "max_cur_depth";
// meanwhile calculate the diameter by adding "max_cur_depth" with the depth of current children being visited.
class Solution {
public:
    int diam = 0;
    
    int diameter(Node* root) {
        depth(root);
        return diam;
    }
    
    int depth(Node* root) {
        if (!root) return 0;
        
        int max_cur_depth = 0;
        for (auto child: root->children) {
            int child_depth = depth(child);
            diam = max(diam, max_cur_depth + child_depth);
            max_cur_depth = max(max_cur_depth, child_depth);
        }
        return max_cur_depth + 1;
    }
};

// METHOD-2: Distance with Height
// The height of a node is defined as the length of the longest downward path to a leaf node from that node.
// height(node) = max(height(child)) + 1, ∀child ∈node.children
// when we traverse the children of a node, we maintain two variables of top 2 largest heights, keep updating them and calculating the longest distance
class Solution {
public:
    int diameter(Node* root) {
        height(root);
        return diameter_;
    }
private:
    int diameter_ = 0;
    
    int height(Node* root) {
        if (root->children.size() == 0) return 0;
        // choose the top two largest heights
        int height1 = 0, height2 = 0;
        for (auto& child: root->children) {
            int parentHeight = height(child) + 1;
            if (parentHeight > height1) {
                height2 = height1;
                height1 = parentHeight;
            } else if (parentHeight > height2) {
                height2 = parentHeight;
            }
            int distance = height1 + height2;
            diameter_ = max(diameter_, distance);
        }
        return height1;
    }
};
