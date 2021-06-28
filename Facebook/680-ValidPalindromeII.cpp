// recursive
class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.length() - 1;
        return validPalindrome(s, l, r, 0);
    }

private:
    bool validPalindrome(string& s, int l, int r, int count) {
        if (count > 1) return false;
        while (l < r) {
            if (s[l] == s[r]) {
                l++; r--;
            } else {
                return validPalindrome(s, l + 1, r, count + 1) || 
                       validPalindrome(s, l, r - 1, count + 1);
            }
        }
        return true;
    }
};


// general method for removing at most K chars:
bool is_valid_palindrome(string& s, int left, int right, int k) {
     while (left <= right) {
        if (s.at(left) == s.at(right)) {
            left++; right--;
        } else {
            if (k > 0) {
                k--;
                return is_valid_palindrome(s, left + 1, right, k) || is_valid_palindrome(s, left, right - 1, k);
            } else 
                return false;
        }
    }
    return true;
}

class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        return is_valid_palindrome(s, left, right, 1);
    }
};

// iterative:
class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1;

        while(i < j) {
            if (s[i] == s[j]) { i++; j--;}
            if (s[i] != s[j]) {
                
                if(s[i+1] != s[j] && s[i] != s[j-1]) {return false;}
                
                bool result1 = true, result2 = true;
                
                if(s[i+1] == s[j]) {
                    int l = i + 1, r = j;
                    while(l < r) {
                        if(s[l] != s[r]) {
                            result1 = false;
                        }
                        l++;
                        r--;
                    }
					          if(result1) {return true;}
                }
                
                if(s[i] == s[j-1]) {
                    int l = i, r = j - 1;
                    while(l < r) {
                        if(s[l] != s[r]) {
                            result2 = false;
                        }
                        l++;
                        r--;
                    }
					          if(result2) {return true;}
                }

                return false;
            }
        }
        return true;     
    }
};
