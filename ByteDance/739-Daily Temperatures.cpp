// monotous stack
// time complexity: O(N)
// Space complexity: O(W) where W is the size of the stack having strctly increasing tempreatures
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> result (n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            // pop stack top until the stack is in ascending order from top to bottom 
            while (!st.empty() && T[i] >= T[st.top()]) st.pop();
            result[i] = st.empty() ? 0 : st.top() - i;
            st.push(i);
        }
        return result;
    }
};
