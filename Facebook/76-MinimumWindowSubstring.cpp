// sliding window: version-1
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> remain(256, 0); //to keep track of remaining char needed in string s
        
        // initialize
        int required = t.length();
        for (char c: t) {
            remain[c]++;
        }
        
        int left = 0, right = 0;
        int min_len = INT_MAX;
        int start_pos = 0;
        
        while (right < s.length()) {
            char c = s[right];
            right++;
            if (remain[c] > 0) required--;
            remain[c]--;
            
            // while all the required chars are in the window
            while (required == 0) {
                // update min_len and start_po
                if (right - left < min_len) {
                    min_len = right - left;
                    start_pos = left;
                }
                // shrink the window
                char d = s[left];
                left++;
                remain[d]++;
                if (remain[d] > 0) required++;
            }
        }
        return min_len == INT_MAX ? "" : s.substr(start_pos, min_len);
    }
};

// version-2
class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() == 0) return t;
        
        vector<int> freqS(256, 0);
        vector<int> freqT(256, 0);
        int unique = 0; // number of unique char in string t
        for (char c: t) {
            freqT[c]++;
            if (freqT[c] == 1) {
                unique++;
            }
        }
        
        int count = 0;
        int left = 0, right = 0;
        int result_l = -1, result_r = -1;
        
        for (left = 0; left < s.length(); left++) {
            while (right < s.length() && count < unique) {
                char c = s[right];
                freqS[c]++;
                if (freqS[c] == freqT[c]) {
                    count++;
                }
                right++;
            }
            
            if (count == unique) {
                if (result_l == -1 || right - left < result_r - result_l) {
                    result_r = right;
                    result_l = left;
                }
            }
            
            char d = s[left];
            freqS[d]--;
            if (freqS[d] == freqT[d] - 1) {
                count--;
            }
        }
        return result_l == -1 ? "" : s.substr(result_l, result_r - result_l);
    }
};
