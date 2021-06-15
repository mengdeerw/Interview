
// hashmap + priority queue
class Solution {
public:
    string rearrangeString(string s, int k) {
        if (k == 0) return s;
        
        unordered_map<char, int> freq;
        for (char& c: s) {
            freq[c]++;
        }
        
        priority_queue<pair<int, char>> pq; // max heap with default comparator {freq, char}
        for (auto& kv: freq) {
            pq.push({kv.second, kv.first});
        }
        
        string result = "";
        int len = s.length();
        while (!pq.empty()) {
            vector<pair<int, char>> remain; // to save the remaining pairs
            int count = min(len, k); // how many chars remained to be dealt with
            for (int i = 0; i < count; i++) {
                if (pq.empty()) return ""; // used up all available char, no possible solutions
                auto pair = pq.top();
                pq.pop();
                result.push_back(pair.second); // use the max frequency char
                pair.first--; // update frequency
                remain.push_back(pair);
                len--;
            }
            
            // update pq with cache
            for (auto& pair: remain) {
                if (pair.first > 0) pq.push(pair);
            }
        }
        return result;
    }
};
