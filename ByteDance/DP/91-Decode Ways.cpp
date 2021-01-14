// METHOD-1: recursion (TLE)
// Time complexity: O(2^N)
class Solution {
public:
    int numDecodings(string s) {
        return s.empty() ? 0 : numDecodings(0, s);
    }
    
    int numDecodings(int pos, string& s) {
        if (pos == s.size()) return 1;
        if (s[pos] == '0') return 0;
        int result = numDecodings(pos + 1, s);
        // checking two coninuous chars
        if (pos < s.size() - 1 && (s[pos] == '1' || s[pos] == '2' && s[pos + 1] <= '6'))
            result += numDecodings(pos + 2, s);
        return result;
    }
};

// METHOD-2: Memorization
// Time Complexity: O(N)
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> memo (n + 1, -1);
        memo[n] = 1;
        return s.empty() ? 0 : num(0, s, memo);
    }
    
    int num(int pos, string& s, vector<int>& memo) {
        if (memo[pos] > -1) return memo[pos];
        if (s[pos] == '0') {
            memo[pos] = 0;
            return memo[pos];
        }
        int result = num(pos + 1, s, memo);
        if (pos < s.size() - 1 && (s[pos] == '1' || s[pos] == '2' && s[pos + 1] <= '6'))
            result += num(pos + 2, s, memo);
        
        memo[pos] = result;
        return memo[pos];
    }
};

// METHOD-3: DP
// Time Complexity: O(N)
// Space complexity: O(N)
class Solution {
public:
    // 从后往前DP，DP[i]代表当前位置到字符串结尾的所有子串的有效decode次数
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp (n + 1);
        dp[n] = 1;
        
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') dp[i] = 0;
            else {
                // one digit
                dp[i] = dp[i + 1];
                // two digit
                if (i < n - 1 && (s[i] == '1' || s[i] == '2' && s[i + 1] <= '6')) {
                    dp[i] += dp[i + 2];
                }
            }
        }
        
        return s.empty() ? 0 : dp[0];
    }
};

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp (n + 1, 0);
        dp[0] = 1;
        
        for (int i = 1; i < n + 1; i++) {
            int num2 = last2(s, i - 1);
            if (s[i - 1] - '0' > 0) dp[i] += dp[i - 1];
            if (num2 >= 10 && num2 <= 26) dp[i] += dp[i - 2];
        }
        return dp[n];
    }
    
    int last2(string& s, int i) {
        int n1 = (i - 1 >= 0) ? s[i - 1] - '0' : 0;
        return n1 * 10 + s[i] - '0';
    }
};

// METHOD-4: DP
// Time Complexity: O(N)
// Space complexity: O(1)
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int p = 1, pp;
        
        for (int i = n - 1; i >= 0; i--) {
            int curr = s[i] == '0' ? 0 : p;
            if (i < n - 1 && (s[i] == '1' || s[i] == '2' && s[i + 1] <= '6'))
                curr += pp;
            pp = p;
            p = curr;
        }
        
        return s.empty() ? 0 : p;
    }
};

