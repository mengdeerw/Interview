/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

// METHOD-1: Dfs
// time complexity: O(N)
// space complexity: O(N) recursive stack
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        return dfs(nestedList, 1);
    }
    
    int dfs(vector<NestedInteger>& nestedList, int depth) {
        int sum = 0;
        for (NestedInteger nested: nestedList) {
            if (nested.isInteger()) {
                sum += nested.getInteger() * depth;
            } else {
                sum += dfs(nested.getList(), depth + 1);
            }
        }
        return sum;
    }
};

// METHOD-2: BFS
// Time complexity:  O(N)
// Space complexity: O(N)
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {   
        queue<NestedInteger> q;
        for (NestedInteger nested: nestedList) {
            q.push(nested);
        }
        
        int sum = 0, depth = 1;
        while (!q.empty()) {
            for (int i = q.size(); i > 0; i--) {
                NestedInteger nested = q.front();
                q.pop();
                if (nested.isInteger()) {
                    sum += nested.getInteger() * depth;
                } else {
                    for (NestedInteger n: nested.getList()) {
                        q.push(n);
                    }
                }
            }
            depth++;
        }
        return sum;
    }
};
