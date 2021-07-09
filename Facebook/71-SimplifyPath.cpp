// Deque
class Solution {
public:
    string simplifyPath(string path) {
        deque<string> dq;
        istringstream ss(path);
        string str;
        while (getline(ss, str, '/')) {
            if (!str.empty()) {
                if (str == ".." && !dq.empty()) {
                    dq.pop_back();
                } else if (str != "." && str != "..") {
                    dq.push_back(str);
                }
            }
        }
        string result = "";
        while (!dq.empty()) {
            result += "/" + dq.front();
            dq.pop_front();
        }
        return result.empty() ? "/" : result;
    }
};

// Stack
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        istringstream ss(path);
        string str;
        while (getline(ss, str, '/')) {
            if (str.empty()) continue; // case "//"
            if (str != "." && str != "..") {
                st.push(str);
            } else if (str == ".." && !st.empty()) {
                st.pop();
            }
        }
        string result = "";
        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }
        return result.empty() ? "/" : result;
    }
};
