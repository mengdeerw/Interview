// backtracking
/*
合法字符串须满足的条件：
1. 一个合法的括号字符串中左括号数量一定等于右括号数量；
2. 对于一个合法的括号字符串s， 必须满足对任何0<=i<len(s)都有：
   子串s[0...i]中左括号的数量都大于等于右括号的数量。
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n == 0) return result;
        string track;
        backtrack(n, n, track, result);
        return result;
        
    }
    
    void backtrack(int left, int right, string& track, vector<string>& result) {
        if (left < 0 || right < 0) return;
        if (right < left) return; // condition 2
        
        // condition 1
        if (left == 0 && right == 0) {
            result.push_back(track);
            return;
        }
        
        track.push_back('(');
        backtrack(left - 1, right, track, result);
        track.pop_back();
        
        track.push_back(')');
        backtrack(left, right - 1, track, result);
        track.pop_back();
    }
};
