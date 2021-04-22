// METHOD-1: catergorized by sorted strings
// time complexity: O(N*KlogK) where N is the length of strs vector, and K is the max. length of a string in strs.
// space complexity: O(NK)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (auto& str: strs) {
            string temp = str;
            sort(temp.begin(), temp.end());
            m[temp].push_back(str);
        }
        
        vector<vector<string>> result;
        for (auto& kv: m) {
            result.push_back(kv.second);
        }
        return result;
    }
};

// METHOD-2: catergorized by counts
// time complexity: O(NK) where N is the length of strs vector, and K is the max. length of a string in strs.
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m; 
        
        for (string& s: strs) {
            vector<int> count(26, 0);
            for (char& c: s) {
                count[c - 'a']++;
            }
            
            string temp = "";
            for (int i = 0; i < 26; i++) {
                temp += "#" + to_string(count[i]);
            }
            
            m[temp].push_back(s);
        }
        
        vector<vector<string>> result;
        for (auto& kv: m) {
            result.push_back(kv.second);
        }
        return result;
    }
};
