/*
sliding window: maintain a sliding window who should contain all the characters present in string T
1. Traverse string T, and record the presence of each character in a hashmap "need"
2. Enlarge the sliding window:
    Slide the right pointer of the window, if all the characters in "need" occur in the window, we record down the current size of the sliding window
3. Narrow the sliding window:
    Slide the left pointer of the window until there are not enough valid chars to compose "need" map.
4. Repeat step 2 & 3 until reach the end of the string T, return the min. size of the window so far.
*/
// time complexity: O(S + T) where S is the length of string s, T is the length of string t
// space complexity: O(2*T)
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        int left = 0, right = 0, valid = 0;
        int len = INT_MAX;
        int start_pos = 0; // start position
        
        for (char& c: t) {
            need[c]++;
        }
        
        while (right < s.length()) {
            // enlarge window
            char cur = s[right];
            right++;
            
            if (need.count(cur)) {
                window[cur]++;
                if (window[cur] == need[cur]) valid++; // update the valid counter of needed chars
            }
            
            // narrow window
            while (valid == need.size()) {
                // update min. len
                if (right - left < len) {
                    len = right - left;
                    start_pos = left;
                }
                
                char d = s[left];
                left++;
                if (need.count(d)) {
                    if (window[d] == need[d]) valid--;
                    window[d]--;
                }
                
            }
        }
        
        return len == INT_MAX ? "" : s.substr(start_pos, len);
    }
};

// optimization: using only one vector to record the remaining chars to be found inside the window
// time complexity: O(S + T) where S is the length of string s, T is the length of string t
// space complexity: O(128)
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> remain(128, 0);
        
        for (auto& c: t) {
            remain[c]++;
        }
        
        int left = 0, right = 0;
        int min_len = INT_MAX, required = t.length();
        int start_pos = 0;
        while (right < s.length()) {
            char c = s[right];
            right++;
            if (remain[c] > 0) required--;
            remain[c]--;
            // narrow window
            while (required == 0) {
                if (right - left < min_len) {
                    min_len = right - left;
                    start_pos = left;
                }
                char d = s[left];
                left++;
                remain[d]++;
                if (remain[d] > 0) required++;
            }
        }
        return min_len == INT_MAX ? "" : s.substr(start_pos, min_len);
    }
};
