// recursion
class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.size() == 0) return word2.size();
        if (word2.size() == 0) return word1.size();
        return match(word1, word2, 0, 0);
    }
    
    int match(string& s1, string& s2, int i, int j) {
        if (s1.size() == i) return s2.size() - j;
        if (s2.size() == j) return s1.size() - i;
        
        int result = 0;
        if (s1[i] == s2[j]) {
            result = match(s1, s2, i + 1, j + 1);
        } else {
            int insert = match(s1, s2, i, j + 1);
            int del = match(s1, s2, i + 1, j);
            int replace = match(s1, s2, i + 1, j + 1);
            result = min(min(insert, del), replace) + 1;
        }
        return result;
    }
};

// dp + memorization
class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.size() == 0) return word2.size();
        if (word2.size() == 0) return word1.size();
        
        vector<vector<int>> memo (word1.size(), vector<int>(word2.size(), -1));
        return match(word1, word2, 0, 0, memo);
    }
    
    int match(string& s1, string& s2, int i, int j, vector<vector<int>>& memo) {
        if (s1.size() == i) return s2.size() - j;
        if (s2.size() == j) return s1.size() - i;
        
        // means memo has already been dealt
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        
        //int result = 0;
        if (s1[i] == s2[j]) {
            memo[i][j] = match(s1, s2, i + 1, j + 1, memo);
        } else {
            int insert = match(s1, s2, i, j + 1, memo);
            int del = match(s1, s2, i + 1, j, memo);
            int replace = match(s1, s2, i + 1, j + 1, memo);
            memo[i][j] = min(min(insert, del), replace) + 1;
        }
        return memo[i][j];
    }
};
