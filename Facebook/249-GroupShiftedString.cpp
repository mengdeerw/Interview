class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> m;
        for (string& s: strings) {
            string encode = shift(s); // enode s to same format
            m[encode].push_back(s);
        }
        vector<vector<string>> result;
        for (auto& [s, group]: m) {
            result.push_back(group);
        }
        return result;
    }
private:
    string shift(string& s) {
        string encode = "";
        int n = s.length();
        for (int i = 1; i < n; i++) {
            int diff = s[i] - s[i - 1];
            if (diff < 0) diff += 26; // zy
            encode += to_string(diff) + ','; // "xyz" => "1,1"
        }
        return encode;
    }
};
