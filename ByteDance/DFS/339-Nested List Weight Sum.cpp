// dfs
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
