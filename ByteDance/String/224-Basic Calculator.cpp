// METHOD-1: recursive (no stack)
// Time complexity: O(N)
class Solution {
public:
    int i = 0;
    int calculate(string s) {
        int num = 0;
        int nextSign = 1;
        int result = 0;
        
        while (i < s.size()) {
            char c = s[i++];
            
            if (isdigit(c) || c == ' ') {
                num = (c == ' ') ? num : 10 * num + (c - '0');
            }
            else if (c == '(') num = calculate(s);            
            else if (c == ')') break;
            else {
                result += nextSign * num;
                nextSign = (c == '+') ? 1 : -1;
                num = 0;
            }
        }
        return result + (nextSign * num);
    }
};

// another version: recursion
class Solution {
public:
    int calculate(string s) {
        int start = 0;
        return helper(s, start);
    }
    
    int helper(string& s, int& i) {
        int num = 0, result = 0;
        int nextSign = 1;
        
        while (i < s.size()) {
            char c = s[i++];
            
            if (isdigit(c) || c == ' ') {
                num = (c == ' ') ? num : 10 * num + (c - '0');
            }
            else if (c == '(') num = helper(s, i);
            else if (c == ')') break;
            else {
                result += nextSign * num;
                nextSign = (c == '+') ? 1 : -1;
                num = 0;
            }
        }
        return result + nextSign * num;
    }
};

// METHOD-2: use stack to deal with parenthesis
// sign represents the sign before individual chars
class Solution {
public:
    int calculate(string s) {
        int result = 0;
        int num = 0, sign = 1;
        stack<int> st;
        
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (isdigit(c) || c == ' ') {
                num = (c == ' ') ? num : num * 10 + (c - '0');
            } else if (c == '+') {
                result += sign * num;
                num = 0; sign = 1; // save sign for next operand
            } else if (c == '-') {
                result += sign * num;
                num = 0; sign = -1; // save sign for next operand
            } else if (c == '(') {
                // push current result & sign into stack
                st.push(result);
                st.push(sign);
                
                result = 0; sign = 1;
            } else if (c == ')') {
                // calculate the sum in between the parenthesis
                result += sign * num;
                result *= st.top(); st.pop(); //sign
                result += st.top(); st.pop(); //num
                num = 0;
            }
        }
        return result + sign*num; // ending is intege: (1 + 3) - 2
    }
};

// another version of stack
class Solution {
public:
    int calculate(string s) {
        int result = 0, num = 0;
        int sign = 1;
        stack<int> st;
        
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            
            if (c == ' ') continue;
            if (isdigit(c)) {
                // continuously read digit
                while (i < s.size() && isdigit(s[i])) {
                    num = 10 * num + (s[i++] - '0');
                }
                result += sign * num;
                i--; num = 0;
            } else if (c == '+') {
                sign = 1;
            } else if (c == '-') {
                sign = -1;
            } else if (c == '(') {
                st.push(result);
                st.push(sign);
                result = 0; 
                sign = 1;
            } else if (c == ')') {
                result *= st.top(); st.pop();
                result += st.top(); st.pop();
            }
        }
        return result;
    }
};
