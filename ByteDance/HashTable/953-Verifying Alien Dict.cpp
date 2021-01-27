// METHOD-1: compare adjacent
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int mapping[26];
        
        for (int i = 0; i < order.size(); i++) {
            mapping[order[i] - 'a'] = i;
        }
        
        for (int i = 0; i < words.size() - 1; i++) {
            string word1 = words[i], word2 = words[i + 1];
            int L1 = word1.size(), L2 = word2.size();
            int minLen = min(L1, L2);
            for (int j = 0; j < minLen; j++) {
                int index1 = word1[j] - 'a', index2 = word2[j] - 'a';
                if (index1 != index2) {
                    if (mapping[index1] > mapping[index2]) return false;
                    else break;
                }
            }
            if (L1 > L2 && word1.substr(0, L2) == word2) return false;
        }
        return true;
    }
};

// METHOD-2: converting to normal order
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int mapping[26];
        
        for (int i = 0; i < 26; i++) {
            mapping[order[i] - 'a'] = i;
        }
        
        for (string &word: words) {
            for (char &c: word) {  // need reference here because we need to convert
                c = mapping[c - 'a'];
            }
        }
        return std::is_sorted(words.begin(), words.end());
    }
};

// METHOD-3: converting to normal order w/0 changing original list
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int mapping[26];
        
        for (int i = 0; i < 26; i++) {
            mapping[order[i] - 'a'] = i;
        }
        
        vector<string> normal (words.begin(), words.end());
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].length(); j++) {
                normal[i][j] = mapping[words[i][j] - 'a'];
            }
        }
        return std::is_sorted(normal.begin(), normal.end());
    }
};

// METHOD-4: converting to normal order
// lambda sorting
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int mapping[26];
        
        for (int i = 0; i < 26; i++) {
            mapping[order[i] - 'a'] = i;
        }
        
        return std::is_sorted(words.begin(), words.end(), [&mapping](const string &w1, const string &w2){
            int l1 = w1.size(), l2 = w2.size();
            for (int i = 0; i < min(l1, l2); i++) {
                int index1 = w1[i] - 'a', index2 = w2[i] - 'a';
                if (index1 != index2) {
                    return mapping[index1] < mapping[index2];
                }
            }
            return l1 < l2;
        });
    }
};
