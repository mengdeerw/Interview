// iterative
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        vector<string> phone = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if (digits.empty()) return result;
        result.push_back("");
        
        for (int i = 0; i < digits.size(); i++) {
            int num = digits[i] - '0';
            string s = phone[num];
            if (s.empty()) continue;
            vector<string> tmp;
            for (int j = 0; j < s.size(); j++) {
                for (int k = 0; k < result.size(); k++) {
                    tmp.push_back(result[k] + s[j]);
                }
            }
            swap(result, tmp);
        }
        return result;
    }
};

// Q: I'm confused about the swap() part. Why do we need the swap? What if we just use result = tmp; there? I did this and it said accepted.
// because swap() is faster, it just swaps the pointer between the two vector,but = involve the copy.
// vector::swap() swaps the reference address in the two vectors and takes O(1) whereas are simple assignment takes O(n), that is why it is used here, though of course it is not necessary.

/*
Initial state:

result = {""}
Stage 1 for number "1":

result has {""}
candiate is "abc"
generate three strings "" + "a", ""+"b", ""+"c" and put into tmp,
tmp = {"a", "b","c"}
swap result and tmp (swap does not take memory copy)
Now result has {"a", "b", "c"}
Stage 2 for number "2":

result has {"a", "b", "c"}
candidate is "def"
generate nine strings and put into tmp,
"a" + "d", "a"+"e", "a"+"f",
"b" + "d", "b"+"e", "b"+"f",
"c" + "d", "c"+"e", "c"+"f"
so tmp has {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" }
swap result and tmp
Now result has {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" }
Stage 3 for number "3":

result has {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" }
candidate is "ghi"
generate 27 strings and put into tmp,
add "g" for each of "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"
add "h" for each of "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"
add "h" for each of "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"
so, tmp has
{"adg", "aeg", "afg", "bdg", "beg", "bfg", "cdg", "ceg", "cfg"
"adh", "aeh", "afh", "bdh", "beh", "bfh", "cdh", "ceh", "cfh"
"adi", "aei", "afi", "bdi", "bei", "bfi", "cdi", "cei", "cfi" }
swap result and tmp
Now result has
{"adg", "aeg", "afg", "bdg", "beg", "bfg", "cdg", "ceg", "cfg"
"adh", "aeh", "afh", "bdh", "beh", "bfh", "cdh", "ceh", "cfh"
"adi", "aei", "afi", "bdi", "bei", "bfi", "cdi", "cei", "cfi" }
*/
