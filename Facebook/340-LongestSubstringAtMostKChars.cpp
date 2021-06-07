// sliding window:
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
