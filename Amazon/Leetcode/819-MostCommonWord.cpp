class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> m;
        unordered_set<string> ban (banned.begin(), banned.end()); 
        // 1. replace all non-alpha chars to white-space; convert alpha chars to lower cases
        for (char& c: paragraph) {
            c = isalpha(c) ? tolower(c): ' ';
        }
        // 2. split words by whitespace and record occurance in map
        stringstream ss(paragraph);
        string token;
        while (ss >> token) {
            if (!ban.count(token)) {
                m[token]++;
            }
        }
        // 3. find the max. occurance of words in map
        string result;
        int count = 0;
        for (auto& kv: m) {
            if (kv.second > count) {
                result = kv.first;
                count = kv.second;
            }
        }
        return result;
    }
};
