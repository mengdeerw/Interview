// METHOD-1: map of map
class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    // single operation O(1), total O(N)
    void set(string key, string value, int timestamp) {
        m[key].insert({timestamp, value});
    }
     
    // single operation: O(logN) total O(MlogN)
    string get(string key, int timestamp) {
        if (m.find(key) == m.end()) return "";
        auto it = m[key].upper_bound(timestamp);
        if (it == m[key].begin()) return "";
        return (--it)->second;
    }
    
private:
    unordered_map<string, map<int, string>> m;
};

// map of vector + binary search
class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    // single operation O(1), total O(N)
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
     
    // single operation: O(logN) total O(MlogN)
    string get(string key, int timestamp) {
        if (!m.count(key)) return "";
        int start = 0, end = m[key].size();
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (m[key][mid].first > timestamp)
                end = mid;
            else
                start = mid + 1;
        }
        return start > 0 && start <= m[key].size() ? m[key][start - 1].second : "";
    }
    
private:
    unordered_map<string, vector<pair<int, string>>> m;
};
