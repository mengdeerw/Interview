class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        
        vector<vector<string>> results;
        while(!q.empty() && results.empty()) {
            unordered_set<string> seen;
            for(int i = q.size() - 1; i >= 0; i--) {
                vector<string> path = q.front(); q.pop();
                vector<string> expand_words = expand(path.back(), words);
                for(auto w : expand_words) {
                    seen.insert(w);
                    path.push_back(w);
                    if(w == endWord) {
                        results.push_back(path);
                    } else {
                        q.push(path);
                    }
                    path.pop_back();
                }
            }
            for(auto &w : seen) words.erase(w);
        }
        return results;
    }
    
    vector<string> expand(string &word, 
                          unordered_set<string>&wordList) {
        
        vector<string> ans;
        for(int i = 0; i < word.size(); i++) {
            auto oldChar = word[i];    
            for(char c = 'a'; c <= 'z'; c++) {
                word[i] = c;
                if(c == oldChar || !wordList.count(word)) continue;
                ans.push_back(word);
            }
            word[i] = oldChar;
        }
        return ans;
    }
};
