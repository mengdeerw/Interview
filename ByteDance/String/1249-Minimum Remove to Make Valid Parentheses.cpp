// Stack
// Time Complexity: O(N)
// Space complexity: O(N)
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st; // how many '(' are there
        unordered_set<int> del; // remaining ')' to be deleted 
        // used a set because it supports random access for searching, 
        // search in unordered_set takes O(1) time in average (worst case O(N))
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (!st.empty()) {
                    st.pop();
                } else {
                    del.insert(i);
                }
            }
        }
        
        while (!st.empty()) {
            del.insert(st.top());
            st.pop();
        }
        
        string result;
        for (int i = 0; i < s.length(); i++) {
            if (del.find(i) == del.end()) {
                result.push_back(s[i]);
            }
        }
        return result;
    }
};

// another version using vector
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        vector<int> del; 
        // search in vector takes O(N) time
        
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '(') {
                st.push(i);
            } else if (c == ')') {
                if (!st.empty()) {
                    st.pop();
                } else {
                    del.push_back(i);
                }
            }
        }
        
        while (!st.empty()) {
            del.push_back(st.top());
            st.pop();
        }
        
        string result;
        for (int i = 0; i < s.size(); i++) {
            auto it = find(del.begin(), del.end(), i);
            if (it == del.end()) {
                result.push_back(s[i]);
            }
        }
        return result;
    }
};
