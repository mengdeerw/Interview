class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int num = 0;
        char op = '+';
        
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (isdigit(c)) {
                num = 10 * num + (c - '0');
            }
            if (c == '(') {
                int j = i + 1, count = 1;
                while (count > 0) {
                    if (s[j] == '(') count++;
                    else if (s[j] == ')') count--;
                    j++;
                }
                num = calculate(s.substr(i + 1, j - i - 1));
                i = j - 1; // adjust cursor to the last calculated character
            }
            if (!isdigit(c) && c != ' ' || i == s.size() - 1) {
                if (op == '+') {
                    st.push(num);
                } else if (op == '-') {
                    st.push(-num);
                } else if (op == '*') {
                    int pre = st.top();
                    st.pop();
                    st.push(pre * num);
                } else if (op == '/') {
                    int pre = st.top();
                    st.pop();
                    st.push(pre / num);
                } 
                op = c;
                num = 0;
            }
        }
        
        int result = 0;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        return result;
    }
};
