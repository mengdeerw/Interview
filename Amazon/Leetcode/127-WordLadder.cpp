//Time Complexity: O(n*26^l) where l = len(word), n=|wordList|

Space Complexity: O(n)


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;
        
        queue<string> q;
        q.push(beginWord);
        
        int step = 0;
        int len = beginWord.length();
        while (!q.empty()) {
            step++; // level
            for (int n = q.size() - 1; n >= 0; n--) { // for the same level
                string word = q.front();
                q.pop();
                for (int i = 0; i < len; i++) {
                    char c = word[i];
                    for (char j = 'a'; j <= 'z'; j++) {
                        word[i] = j;
                        if (word == endWord) return step + 1;
                        if (!dict.count(word)) continue;
                        dict.erase(word);
                        q.push(word);
                    }
                    word[i] = c;
                }
            }
        }
        return 0;
    }
};
