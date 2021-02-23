// BFS + Topogical sort
class Solution {
public:
    string alienOrder(vector<string>& words) {
        if (words.size() == 0) return "";
        unordered_map<char, int> indegree;
        unordered_map<char, unordered_set<char>> graph;
        
        // step1 - initialize
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                char c = words[i][j];
                indegree[c] = 0;
            }
        }
        
        // step2 - build graph and record indegree
        for (int i = 0; i < words.size() - 1; i++) {
            string curr = words[i];
            string next = words[i + 1];
            int len = min(curr.length(), next.length());
            for (int j = 0; j < len; j++) {
                if (curr[j] != next[j]) {
                    unordered_set<char> set = graph[curr[j]];
                    if (set.find(next[j]) == set.end()) {
                        graph[curr[j]].insert(next[j]); //build graph
                        indegree[next[j]]++;  //add indegree
                    }
                    break;
                }
                if (j == len - 1 && curr.size() > next.size()) return ""; //consider ["abc" "ab"]
            }
        }
        
        // step3- topological sort
        string result;
        queue<char> q;
        for (auto kv: indegree) {
            if (kv.second == 0)
                q.push(kv.first);
        }
        while (!q.empty()) {
            char curr = q.front();
            q.pop();
            result += curr;
            
            if (graph[curr].size() != 0) {
                for (auto c: graph[curr]) {
                    indegree[c]--;
                    if (indegree[c] == 0)
                        q.push(c);
                }
            }
        }
        
        // step4 - check if it is cyclic
        return result.length() == indegree.size() ? result : "";
    }
};
