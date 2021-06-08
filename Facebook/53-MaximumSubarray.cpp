// METHOD-1: brute force
// time complexity: O(N^2)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int max_sum = INT_MIN;
        
        for (int i = 0; i < n; i++) {
            int cur_sum = 0; // sum of nums[i...j]
            for (int j = i; j < n; j++) {
                cur_sum += nums[j];
                max_sum = max(max_sum, cur_sum);
            }
        }
        return max_sum;
    }
};

// METHOD-2: dp
// time complexity: O(N)
// space complexity: O(N)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0); // dp[i] = max sum in range nums[0...i - 1]
        dp[0] = nums[0];
        
        for (int i = 1; i < n; i++) {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};

// METHOD-3: dp
// time complexity: O(N)
// space complexity: O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int cur_sum = nums[0], max_sum = nums[0];
        
        for (int i = 1; i < n; i++) {
            cur_sum = max(cur_sum + nums[i], 0 + nums[i]); // if cur_sum is negative, throw it away and start a new count
            max_sum = max(max_sum, cur_sum);
        }
        return max_sum;
    }
};

// METHOD-4: Divide and conquer
// time complexity: O(NlogN)
// space complexity: O(1)
class Solution {
public:
    vector<int> numsArray;
    
    int maxSubArray(vector<int>& nums) {
        numsArray = nums;
        
        // Our helper function is designed to solve this problem for
        // any array - so just call it using the entire input!
        return findBestSubarray(0, numsArray.size() - 1);
    }
    
private:
    int findBestSubarray(int left, int right) {
        // Base case - empty array.
        if (left > right) {
            return INT_MIN;
        }
        
        int mid = left + (right - left) / 2;
        int curr = 0;
        int bestLeftSum = 0;
        int bestRightSum = 0;
        
        // Iterate from the middle to the beginning.
        for (int i = mid - 1; i >= left; i--) {
            curr += numsArray[i];
            bestLeftSum = max(bestLeftSum, curr);
        }
        
        // Reset curr and iterate from the middle to the end.
        curr = 0;
        for (int i = mid + 1; i <= right; i++) {
            curr += numsArray[i];
            bestRightSum = max(bestRightSum, curr);
        }
        
        // The bestCombinedSum uses the middle element and the best
        // possible sum from each half.
        int bestCombinedSum = numsArray[mid] + bestLeftSum + bestRightSum;
        
        // Find the best subarray possible from both halves.
        int leftHalf = findBestSubarray(left, mid - 1);
        int rightHalf = findBestSubarray(mid + 1, right);
        
        // The largest of the 3 is the answer for any given input array.
        return max(bestCombinedSum, max(leftHalf, rightHalf));
    }
};
