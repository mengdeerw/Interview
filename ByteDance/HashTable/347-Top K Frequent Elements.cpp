// pq(max Heap) + map
// Time complexity: O(NlogM) where M is the number of unique elements in nums vector
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;           
        for (int num: nums) {
            m[num]++;
  
        }
        
        auto cmp = [](auto& a, auto& b) {
            return a.second < b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq (cmp);
        for (auto p: m) {
            pq.push({p.first, p.second});
        }
        
        vector<int> result;
        for (int i = 1; i <= k; i++)
        {
            result.push_back(pq.top().first);
            pq.pop();
        }
        
        return result;
    }
};

// pq (min heap) + map
// Time complexity: O(NlogK)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;           
        for (int num: nums) {
            m[num]++;
  
        }
        
        auto cmp = [](auto& a, auto& b) {
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq (cmp);
        for (auto p: m) {
            pq.push({p.first, p.second});
            if (pq.size() > k) pq.pop(); // pop the smallest element to maintain a pq of size k
        }
        
        vector<int> result (k);
        for (int i = k - 1; i >= 0; i--)
        {
            result[i] = pq.top().first;
            pq.pop();
        }
        
        return result;
    }
};
