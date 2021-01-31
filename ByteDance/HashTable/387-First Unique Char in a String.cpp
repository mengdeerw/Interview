// METHOD-1: two passes
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        for (auto c: s) {
            m[c]++;
        }
        
        for (int i = 0; i < s.length(); i++) {
            if (m[s[i]] == 1) return i;
        }
        return -1;
    }
};

// METHOD-2: one pass
// in case string s is extremely long
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, pair<int, int>> m;        
        for (int i = 0; i < s.length(); i++) {
            m[s[i]].first++;
            m[s[i]].second = i;
        }
        int index = s.length();
        for (auto kv: m) {
            if (kv.second.first == 1) index = min(index, kv.second.second);
        }
        return index == s.length() ? -1 : index;
    }
};
