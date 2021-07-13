class Solution {
public:
    int minAddToMakeValid(string s) {
        int balance = 0;
        int result = 0;
        
        for (char& c: s) {
            balance += (c == '(') ? 1 : -1;
            // since '(' needs to be always before ')' 
            if (balance == -1) { // means we must add ( before going further; consider ())...
                result++;
                balance++;
            }
            // balance will always be larger or equal to 0
        }
        result += balance;
        return result;
    }
};
