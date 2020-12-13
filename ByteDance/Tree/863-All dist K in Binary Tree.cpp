/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// METHOD-1:Use DFS to build the graph, and use BFS to find all the nodes that are exact K steps from target.
// Time complexity: O(N)
// Space complexity: O(N)
class Solution {
public:
    unordered_map<TreeNode*, vector<TreeNode*>> graph;
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        //build graph
        buildGraph(NULL, root);
        
        vector<int> ans;
        vector<TreeNode*> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited.push_back(target);
        
        int k = 0;
        while (!q.empty()) {
            if (k > K) break;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front(); q.pop();
                if (k == K) ans.push_back(node->val);
                for (TreeNode* child: graph[node]) {
                    if (find(visited.begin(), visited.end(), child) != visited.end()) continue;
                    q.push(child);
                    visited.push_back(child);
                }
            }
            k++;
        }
        return ans;
    }
    
    void buildGraph(TreeNode* parent, TreeNode* child) {
        if (parent) {
            graph[child].push_back(parent);
            graph[parent].push_back(child);
        }
        if (child->left) buildGraph(child, child->left);
        if (child->right) buildGraph(child, child->right);
    }
};

// METHOD-2: DFS recursion: compute distance from root to target and collect nodes accordingly
// Time complexity: O(N)
// Space complexity: O(N)
class Solution {
public:
    vector<int> ans;
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        dis(root, target, K);
        return ans;
    }
    
    // DFS: returns the distance from root to target; returns -1 if target not found
    int dis(TreeNode* root, TreeNode* target, int K) {
        if (!root) return -1;
        if (root == target) {
            collect(target, K);
            return 0;
        }
        
        int left = dis(root->left, target, K);
        int right = dis(root->right, target, K);
        
        // if target is in left subtree
        if (left >= 0) {
            if (left == K - 1) ans.push_back(root->val);
            // collect nodes in right subtree whose depth is K - left - 2
            collect(root->right, K - left - 2);
            return left + 1;
        }
        
        if (right >= 0) {
            if (right == K - 1) ans.push_back(root->val);
            collect(root->left, K - right - 2);
            return right + 1;
        }
        return -1;
    }
    
    // collect nodes that are n steps from root
    void collect(TreeNode* root, int n) {
        if (!root) return;
        if (n == 0) ans.push_back(root->val);
        collect(root->left, n - 1);
        collect(root->right, n - 1);
    }
};
