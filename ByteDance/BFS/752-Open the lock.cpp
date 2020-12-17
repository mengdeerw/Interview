// Bidirectional BFS
// 分别从'0000'以及target出发进行BFS，直到路径重合
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dds (deadends.begin(), deadends.end());
        unordered_set<string> q1, q2, visited;
        
        q1.insert("0000");
        q2.insert(target);
        int step = 0;
        
        while (!q1.empty() && !q2.empty()) {
            // enhancement: always starts from the set that has fewer elements
            if (q1.size() > q2.size()) swap(q1, q2);
            
            unordered_set<string> temp;
            for (string s: q1) {
                if (dds.count(s)) continue;
                if (q2.count(s)) return step; // intersection found
                visited.insert(s);
                
                for (int i = 0; i < 4; i++) {
                    string up = s;
                    up[i] = (s[i] == '9') ? '0' : s[i] + 1;
                    if (!visited.count(up)) temp.insert(up);
                    string down = s;
                    down[i] = (s[i] == '0') ? '9' : s[i] - 1;
                    if (!visited.count(down)) temp.insert(down);
                }
                
            }
            step++;
            // next while will do BFS in q2
            swap(q1, temp);
        }
        return -1;
    }
};


// TLE: one direction BFS
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int step = 0;
        unordered_set<string> deads;
        for (string d: deadends) {
            deads.insert(d);
        }
        
        unordered_set<string> visited;
        queue<string> q;
        q.push("0000");
        visited.insert("0000");
        
        while (!q.empty()) {
            int n = q.size();
            
            for (int i = 0; i < n; i++) {
                string curr = q.front();
                q.pop();
                // is valid
                if (deads.count(curr)) continue;
                if (curr == target) return step;
                
                // permute possible moves
                for (int j = 0; j < 4; j++) {
                    string up = plusOne(curr, j);
                    if (!visited.count(up)) {
                        q.push(up);
                        visited.insert(up);
                    }
                    string down = minusOne(curr, j);
                    if (!visited.count(down)) {
                        q.push(down);
                        visited.insert(down);
                    }
                }
            }
            step++;
        }
        return -1;
    }
    
    // move s[i] upwards once
    string plusOne(string& s, int i) {
        return s.substr(0, i) + to_string(s[i] == '9' ? 0 : s[i] - '0' + 1) + s.substr(i + 1);
    }
    
    // move s[i] downwards once
    string minusOne(string& s, int i) {
        return s.substr(0, i) + to_string(s[i] == '9' ? 0 : s[i] - '0' - 1) + s.substr(i + 1);
    }
};
