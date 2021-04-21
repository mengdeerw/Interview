// O(NlogK) time
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // O(1) time
        if (k == nums.size()) {
            return nums;
        }
        
        // 1. build map to record frequency: O(N) time
        unordered_map<int, int> m;
        for (int num: nums) {
            m[num]++;
        }
        //min heap
        auto cmp = [](auto& a, auto& b) {
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        // 2. keep top k frequent elements in the pq: O(NlogK) time
        for (auto& kv: m) {
            pq.push(kv); 
            if (pq.size() > k) pq.pop();
        }
        // 3. build output array: O(KlogK) time
        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().first);
            pq.pop();
        }
        return result;
    }
};
