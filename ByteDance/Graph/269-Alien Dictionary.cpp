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

// DFS
class Solution {
public:
    unordered_map<char, vector<char>> graph;
    unordered_map<char, bool> visited;
    string result;
    
    string alienOrder(vector<string>& words) {
        //step 1: initialize
        for (string word: words) {
            for (char c: word) {
                graph[c] = {};
            }
        }
        
        //step 2: build graph
        for (int i = 0; i < words.size() - 1; i++) {
            string word1 = words[i];
            string word2 = words[i + 1];
            int len = min(word1.length(), word2.length()); 
            for (int j = 0; j < len; j++) {
                if (word1[j] != word2[j]) {
                    graph[word1[j]].push_back(word2[j]);
                    break;
                }
            }
            
            if (word1.find(word2) == 0 && word1.length() > word2.length()) return "";
        }
        
        // step 3: DFS
        for (auto kv: graph) {
            char c = kv.first;
            bool noCycle = dfs(c);
            if (!noCycle) return "";
        }
        
        if (result.length() < graph.size()) return "";
        
        reverse(result.begin(), result.end());
        return result;
    }
    
    // return true if no cycles
    bool dfs(char c) {
        if (visited.find(c) != visited.end()) {
            return visited[c];
        }
        visited[c] = false;
        for (char next: graph[c]) {
            bool noCycle = dfs(next);
            if (!noCycle) return false;
        }
        visited[c] = true;
        result += c;
        return true;
    }
};
