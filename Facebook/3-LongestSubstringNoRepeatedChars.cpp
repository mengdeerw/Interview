// two pointers to construct a sliding window
// 1. keep moving right pointer to increase the size of the window
// 2. if we meet repeated char while increasing the window, shrink the window by moving left pointer until no repeated chars inside the window
// so we will need a hashtable to record the frequency of a certain character
// time complexity: O(2 * N)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> char2freq;
        int left = 0, right = 0;
        int max_len = 0;
        while (right < s.length()) {
            char c = s[right];
            char2freq[c]++;
            right++;
            while (char2freq[c] >= 2) { // if we meet repeated char
                char d = s[left];
                left++;
                char2freq[d]--;
            }
            // at this point, there is no repeated chars inside the window, so we need to update longest length
            max_len = max(max_len, right - left); 
        }
        return max_len;
    }
};

// Optimized sliding window
// 1. keep moving right pointer to increase the size of the window
// 2. if we meet repeated char while increasing the window, shrink the window by moving left pointer until no repeated chars inside the window
// (an optimal way for this step is to jump left pointer directly to the new index where there is no repeating chars inisde the window)
// so we will need a hashtable to record the last index of a certain character that we met before
// time complexity: O(N)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> char2idx(128, -1);
        int left = 0, right = 0;
        int max_len = 0;
        while (right < s.length()) {
            char c = s[right];
            int index = char2idx[c];
            // check if index is valid
            if (index != -1 && index < right && index >= left) {
                left = index + 1;
            }
            // at this point, there is no repeated chars inside the window, so we need to update longest length
            max_len = max(max_len, right - left + 1);
            char2idx[c] = right; // update the last index of this char
            right++;    
        }
        return max_len;
    }
};
