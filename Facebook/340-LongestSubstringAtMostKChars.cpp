// METHOD-1: sliding window
// maintain a sliding window that only contains at most k distinct chars
// time complexity: O(N)
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k < 1) return 0;
        
        unordered_map<char, int> char2freq;
        int left = 0, right = 0;
        int max_len = 0;
        while (right < s.length()) {
            char c = s[right];
            char2freq[c]++;
            right++;
            while (char2freq.size() > k) {
                char d = s[left];
                char2freq[d]--;
                left++;
                if (char2freq[d] == 0) { // if meet new char
                    char2freq.erase(d);
                }
            }
            max_len = max(max_len, right - left);
        }
        return max_len;
    }
};

// METHOD-2: sliding window
// two pointers with a variable to count distinct char inside the window
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k < 1) return 0;
        vector<int> freq (128, 0);
        int left = 0, right = 0;
        int max_len = 0;
        int num_distinct = 0;
        while (right < s.length()) {
            char c = s[right];
            freq[c]++;
            right++;
            if (freq[c] == 1) { // new char
                num_distinct++;
            }
            if (num_distinct <= k) {
                // update max length
                max_len = max(max_len, right - left);
            }
            while (num_distinct > k) { // need to shrink window
                char d = s[left]; 
                freq[d]--;
                left++;
                if (freq[d] == 0) {
                    num_distinct--;
                }
            }

        }
        return max_len;
    }
};
