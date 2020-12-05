// dp
// time complexity: O(N^2)
// space complexity: O(N^2)
class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> m; // {position: set{jumpsize}}
        for (int stone: stones) {
            m[stone] = {};
        }
        m[0].insert(0);
        for (int i = 0; i < stones.size(); i++) {
            for (int k: m[stones[i]]) {
                for (int jump = k - 1; jump <= k + 1; jump++) {
                    if (jump > 0 && m.find(stones[i] + jump) != m.end()) {
                        m[stones[i] + jump].insert(jump);
                    }
                }
            }
        }
        return m[stones.back()].size() > 0;
    }
};

// recursion
class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, bool> m; // {position: whether frog can jump}
        return helper(stones, 0, 0, m);
    }
    /*
    The number of stones is less than 1100 so pos will always be less than 2^11 (2048).
Stone positions could be theoretically up to 2^31 but k is practically not possible to be that big for the parameter as the steps must start from 0 and 1 and at the 1100th step the greatest valid k would be 1100. So combining pos and k is safe here.
    */
    bool helper(vector<int>& stones, int pos, int jump, unordered_map<int, bool>& m) {
        int key = pos | jump << 11;
        if (pos >= stones.size() -1) return true;
        if (m.count(key)) return m[key];
        for (int i = pos + 1; i < stones.size(); i++) {
            int dist = stones[i] - stones[pos];
            if (dist < jump - 1) continue;
            if (dist > jump + 1) return m[key] = false;
            if (helper(stones, i, dist, m)) return m[key] = true;
        }
        return m[key] = false;
    }
};
