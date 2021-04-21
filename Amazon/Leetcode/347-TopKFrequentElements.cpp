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

// The average time complexity for Bucket Sort is O(n + k). The worst time complexity is O(n²).
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int num: nums) {
            m[num]++;
        }
        
        vector<vector<int>> bucket(nums.size() + 1);
        for (auto& kv: m) {
            bucket[kv.second].push_back(kv.first);
        }
        
        vector<int> result;
        for (int i = bucket.size() - 1; i >= 0; i--) {
            for (int num: bucket[i]) {
                if (result.size() == k) break;
                result.push_back(num);
            }
        }
        return result;
    }
};
