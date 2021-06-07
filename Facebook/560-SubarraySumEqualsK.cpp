// brute force - TLE
// time complexity: O(N^3)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, n = nums.size();
        for (int start = 0; start < n; start++) {
            for (int end = start + 1; end <= n; end++) {
                int sum = 0;
                for (int i = start; i < end; i++) {
                    sum += nums[i];
                }
                if (sum == k) {
                    count++;
                }
            }
        }
        return count;
    }
};

// METHOD-2: prefix sum array - TLE
// time complexity: O(N^2)
// space complexity: O(N)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, n = nums.size();
        vector<int> prefix (n + 1, 0); // prefix[i] is the sum of nums[0...i - 1]
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        for (int start = 0; start < n; start++) {
            for (int end = start + 1; end <= n; end++) {
                if (prefix[end] - prefix[start] == k) {
                    count++;
                }
            }
        }
        return count;
    }
};

// METHOD-3: prefix sum without space - TLE
// time complexity: O(N^2)
// space complexity: O(1)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, n = nums.size();
        for (int start = 0; start < n; start++) {
            int prefix = 0; // the sum between range [start, end - 1]
            for (int end = start; end < n; end++) {
                prefix += nums[end];
                if (prefix == k) {
                    count++;
                }
            }
        }
        return count;
    }
};

// METHOD-4: map of preSum
// Time complexity: O(N)
// Space complexity: O(N)
/* 
 1. calculate the prefix sum of [0...i], notate as prefix[i];
 2. the purpose is to find the prefix sum = prefix[i] - k;
 3. so we can convert this problem into 2sum, using a hashtable to record the frequency of a certain prefix sum that is equal to prefix[i] - k;
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> sum2freq; 
        // very important!!!
        sum2freq[0] = 1;
        
        int count = 0, preSum = 0;
        for (int i = 0; i < n; i++) {
            preSum += nums[i];
            int target = preSum - k;
            if (sum2freq.find(target) != sum2freq.end()) {
                count += sum2freq[target];
            }
            sum2freq[preSum]++;
        }
        return count;
    }
};
