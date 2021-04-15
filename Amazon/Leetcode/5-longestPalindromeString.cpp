class Solution {
public:
    // expand from center
    string longestPalindrome(string s) {
        string result;
        for (int i = 0; i < s.length(); i++) {
            string s1 = palindrome(s, i, i);
            string s2 = palindrome(s, i, i + 1);
            result = result.length() > s1.length() ? result : s1;
            result = result.length() > s2.length() ? result : s2;
        }
        return result;
    }
    
    string palindrome(string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // [left + 1, right - 1]
        return s.substr(left + 1, right - left - 1); // substr(int start_index, int len)
    }
};
