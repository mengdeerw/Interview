// stack
// space complexity: O(N)
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return makeString(s) == makeString(t);
    }
private:
    string makeString(string& s) {
        stack<char> st;
        for (char c: s) {
            if (c == '#') {
                if (!st.empty()) st.pop();
            }
            else st.push(c);
        }
        string result;
        while (!st.empty()) {
            result = result + st.top();
            st.pop();
        }
        return result;
    }
};

// two pointers
// space complexity: O(1)
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.length() - 1, j = t.length() - 1;
        int skipS = 0, skipT = 0;
        while (i >= 0 || j >= 0) {
            // find the position of next possible char in s
            while (i >= 0) { 
                if (s[i] == '#') {
                    skipS++; i--;
                } else if (skipS > 0) {
                    skipS--; i--;
                } else break;
            }
            while (j >= 0) {
                if (t[j] == '#') {
                    skipT++; j--;
                } else if (skipT > 0) {
                    skipT--; j--;
                } else break;
            }
            if (i >= 0 && j >= 0 && s[i] != t[j]) return false;
            if ((i >= 0) != (j >= 0)) return false;
            i--; j--;
        }
        return true;
    }
};
