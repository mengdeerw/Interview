// Map with sliding window
// time complexity: O(N)
// space complexity: O(min(M, N)) where N is the size of string, and M is the size of the map

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int result = 0;
        
        for (int i = 0, j = 0; j < s.length(); j++) {
            // check if s[j] already in map
            if (m.find(s[j]) != m.end()) {
                i = max(i, m[s[j]]); // reset left boundary of sliding window
            }
            result = max(result, j - i + 1);
            m[s[j]] = j + 1;
        }
        return result;
    }
};
