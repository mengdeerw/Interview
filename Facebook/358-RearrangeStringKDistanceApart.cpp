class Solution {
public:
    string rearrangeString(string s, int k) {
        if (k == 0) return s;
        
        unordered_map<char, int> m;
        for (char c: s) {
            m[c]++;
        }
        
        priority_queue<pair<int, char>> pq; // max heap {count, char}
        for (auto& kv: m) {
            pq.push(make_pair(kv.second, kv.first));
        }
        
        string result;
        int len = s.length();
        while (!pq.empty()) {
            vector<pair<int, char>> cache;
            int count = min(len, k);
            for (int i = 0; i < count; i++) {
                if (pq.empty()) return "";
                auto pair = pq.top();
                pq.pop();
                result.push_back(pair.second);
                pair.first--;
                if (pair.first > 0) {
                    cache.push_back(pair);
                }
                len--;
            }
            for (auto p: cache) {
                pq.push(p);
            }
        }
        return result;
    }
};
