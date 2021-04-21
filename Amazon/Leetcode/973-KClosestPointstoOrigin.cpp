class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // max heap
        auto cmp = [](auto& a, auto& b){
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        for (auto point: points) {
            pq.push(point);
            if (pq.size() > k) pq.pop();
        }
        vector<vector<int>> result;
        while (!pq.empty()) {
            result.push_back(pq.top());
            pq.pop();
        }
        return result;
    }
};
