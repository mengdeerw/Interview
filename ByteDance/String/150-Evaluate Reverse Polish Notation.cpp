class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto s: tokens) {
            if (s.size() > 1 || isdigit(s[0])) {
                st.push(stoi(s));
            } else { // operators
                auto x2 = st.top(); st.pop();
                auto x1 = st.top(); st.pop();
                if (s == "+") x1 += x2; 
                else if (s == "-") x1 -= x2; 
                else if (s == "*") x1 *= x2; 
                else if (s == "/") x1 /= x2; 
                st.push(x1);
            }
        }
        return st.top();
    }
};
