// time complexity: O(N)
// space complexity: O(26) ~ O(1)

// METHOD-1
/* two passes: 
-1st-pass: record char count and index in a map
-2nd-pass: check the map to find the unique count with lowest index.
*/
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, pair<int, int>> m;
        for (int i = 0; i < s.size(); i++) {
            m[s[i]].first++;
            m[s[i]].second = i;
        }
        
        int result = INT_MAX;
        for (auto kv: m) {
            if (kv.second.first == 1) {
                result = min(result, kv.second.second);
            }
        }
        return result == INT_MAX ? -1 : result;
    }
};

// METHOD-2: no need to record index in the map
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

// METHOD-3 faster: use a hashtable instead of map
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> count(26, 0);
        int n = s.size();
        for (int i = 0; i < n; i++) {
            count[s[i] - 'a']++;
        }
        for (int i = 0; i < n; i++) {
            if (count[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};
