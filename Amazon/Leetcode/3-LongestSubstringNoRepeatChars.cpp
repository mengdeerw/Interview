// METHOD-1: normal sliding window
// time complexity: O(2N)
// Space complexity: O(min(M, N)) where M is the size of the char-set.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        int left = 0, right = 0; 
        int result = 0;
        while (right < s.size()) {
            char c = s[right];
            window[c]++;
            right++;
            
            while (window[c] > 1) { // repeated element
                char d = s[left];
                // move left pointer
                left++;
                window[d]--;
            }
            result = max(result, right - left);
        }
        return result;
    }
};

// METHOD-2: optimized sliding window
// time complexity: O(N)
// space complexity: O(128)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> index(128, -1);
        
        int left = 0, right = 0;
        int result = 0;
        while (right < s.size()) {
            char r = s[right];
            int idx = index[r];
            if (idx != -1 && idx >= left && idx < right) { // if repeated char
                left = idx + 1; // change starting point
            }
            result = max(result, right - left + 1);
            index[r] = right; // update last index
            right++;
        }
        return result;
    }
};

// another version
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> index;
        int result = 0;
        
        for (int i = 0, j = 0; j < s.size(); j++) {
            i = max(i, index[s[j]]); // update starting point
            result = max(result, j - i + 1);
            index[s[j]] = j + 1; // update last index
        }
        
        return result;
    }
};
