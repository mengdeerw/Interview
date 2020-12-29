// Sliding window
// Time complexity: O(N)
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for (char c: t) {
            need[c]++;
        }
        
        int left = 0, right = 0, valid = 0;
        int len = INT_MAX;
        int start = 0;
        while (right < s.size()) {
            // c是移入窗口的字符
            char c = s[right];
            right++;
            // 更新窗口内的数据
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++; //表示窗口中满足need条件的字符个数
                }
            }
            
            // 判断左侧窗口是否需要收缩
            while (valid == need.size()) { //说明窗口已经完全覆盖了字符串t
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }
                // d是即将移出窗口的字符
                char d = s[left];
                left++;
                if (need.count(d)) {
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
