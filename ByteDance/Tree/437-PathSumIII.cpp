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

// prefix sum + hash map
class Solution {
public:
    int targetSum = 0, result = 0;
    unordered_map<int, int> seen;
    
    // do preorder traversal
    void dfs(TreeNode* root, int prefixSum) {
        if (!root) return;
        // update prefix sum so far
        prefixSum += root->val;
        // case1: path starting from the root
        if (prefixSum == targetSum) result++;
        // case2: path starting from the middle of the tree
        // if any interval summing up to target sum, calculate the number of nodes within that interval
        result += seen[prefixSum - targetSum];
        // update map
        seen[prefixSum]++;
        // search left and right subtree
        dfs(root->left, prefixSum);
        dfs(root->right, prefixSum);
        // remove the current sum from map, backtracking
        seen[prefixSum]--;
    }
    
    int pathSum(TreeNode* root, int sum) {
        targetSum = sum;
        dfs(root, 0);
        return result;
    }
};

// dfs + recursion
class Solution {
public:
    int result = 0;
    
    int pathSum(TreeNode* root, int sum) {
        if (!root) return result;
        sumUp(root, sum);
        pathSum(root->left, sum);
        pathSum(root->right, sum);
        return result;
    }
    
    // check if contains any desired paths.
    void sumUp(TreeNode* root, int sum) {
        if (!root) return;
        if (root->val == sum) result++;
        sumUp(root->left, sum - root->val);
        sumUp(root->right, sum - root->val);
    }
};

// DFS + recursion
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        return pathSumFromRoot(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
    
    int pathSumFromRoot(TreeNode* root, int sum) {
        if (!root) return 0;
        int count = root->val == sum ? 1 : 0;
        return count + pathSumFromRoot(root->left, sum - root->val) + pathSumFromRoot(root->right, sum - root->val);
    }
};
