// METHOD-1: using 1 stack
class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ']') {
                st.push(s[i]);
            } else {
                string decodeString = "";
                while (st.top() != '[') {
                    decodeString += st.top();
                    st.pop();
                }
                // pop [ from stack
                st.pop();
                int base = 1, times = 0;
                while (!st.empty() && isdigit(st.top()) {
                    times = times + (st.top() - '0') * base;
                    st.pop();
                    base *= 10;
                }
                while (times != 0) {
                    for (int j = decodeString.length() - 1; j >= 0; j--) {
                        st.push(decodeString[j]);
                    }
                    times--;
                }
            }
        }
        
        string result;
        for (int i = st.size() - 1; i >= 0; i--) {
            result = st.top() + result;
            st.pop();
        }
        return result;
    }
};
                       
// METHOD-2: Using 2 stacks
class Solution {
public:
    string decodeString(string s) {
        stack<int> countSt;
        stack<string> stringSt;
        string str;
        int k = 0;
        for (char c: s) {
            if (isdigit(c)) {
                k = k * 10 + c - '0';
            } else if (c == '[') {
                countSt.push(k);
                stringSt.push(str);
                str = ""; // reset str
                k = 0;
            } else if (c == ']') {
                string decodeString = stringSt.top();
                stringSt.pop();
                for (int i = countSt.top() - 1; i >= 0; i--) {
                    decodeString += str;
                }
                countSt.pop();
                str = decodeString;
            } else {
                str += c;
            }
        }
        return str;
    }
};
                       
// METHOD-3: recursion
class Solution {
public:
    string decodeString(string s) {
        int index = 0;
        return decodeString(s, index);
    }
    
    string decodeString(string& s, int& index) {
        string result;
        while (index < s.length() && s[index] != ']') {
            if (!isdigit(s[index])) {
                result += s[index++];
            } else {
                int k = 0;
                while (index < s.length() && isdigit(s[index])) {
                    k = k * 10 + s[index++] - '0';
                }
                index++; // opening bracket '['
                string str = decodeString(s, index);
                index++; // closing bracket ']'
                while (k-- > 0) {
                    result += str;
                }
            }
        }
        return result;
    }
};
