// METHOD-1: preSum
// Time complexity: O(N^2)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> preSum (n + 1); // preSum[i] -> sum of nums[0...i - 1]
        preSum[0] = 0;
        for (int i = 0; i < n; i++) {
            preSum[i + 1] = preSum[i] + nums[i];
        }
        
        int result = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                // sum of num[j...i - 1]
                if (preSum[i] - preSum[j] == k) {
                    result++;
                }
            }
        }
        return result;
    }
};


// METHOD-2: map of preSum
// Time complexity: O(N)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> m; // {preSum->number of occurence of this preSum}
        m[0] = 1; // initialize
        
        int count = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i]; // sum of nums[0...i]
            int target = sum - k; // target
            if (m.find(target) != m.end()) {
                count += m[target];
            }
            m[sum]++;
        }
        return count;
    }
};
