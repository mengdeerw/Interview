class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        int left = 0, right = 0;
        int result = 0;
        
        while (right < s.size()) {
            char c = s[right];
            right++;
            window[c]++;
            
            // 存在重复元素
            while (window[c] > 1) {
                char d = s[left];
                left++;
                window[d]--;
            }
            
            result = max(result, right - left);
        }
        return result;
    }
};
