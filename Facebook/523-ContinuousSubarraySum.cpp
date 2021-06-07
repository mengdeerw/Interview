/*
//A proof sketch:
// Suppose sum_i represents the running sum starting from index 0 and ending at i
// once we find a mod that has been seen, say modk, we have:

// current one: sum_i = m*k + modk
// previous one: sum_j = n*k + modk
// Thus,
// sum_i - sum_j = (m - n) *k

//so if two runningSum mod k have the same values, then when they are subtracted, they are bound to be multiples of k

//Create a hashmap of the running_sum remainder and it's respective index

//Why to insert <0,-1> for the hashmap:
// <0,-1> can allow it to return true when the runningSum%k=0,

//for example [1,2,3] is input and k=6
//then the remainders are [ 1,3,0] i.e runningSum = runningSum%k
//now 1+2+3=6 which is actually a multiple of 6 and hence 0 should be stored in the hashmap

//ok - but why -1?
//-1 is good for storing for 0 because - it will remove the case where we consider only the first element which alone may be a multiple as 0-(-1) is not greater than 1

// In addition, it also avoids the first element of the array is the multiple of k, since 0-(-1)=1 is not greater than 1.
*/

// time complexity: O(N)
// space complexity: O(N)
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2) return false;
        
        unordered_map<int, int> m; // {remainder: index}
        m[0] = -1; // initialize
        int prefix = 0;
        for (int i = 0; i < n; i++) {
            prefix += nums[i];
            
            if (k != 0) {
                prefix %= k; // we always save the remainder
            }
            
            // check if this prefix is already in the map
            if (m.find(prefix) != m.end()) {
                // check if the subarray's size is larger or equal than 2
                int pre_idx = m[prefix];
                if (i - pre_idx >= 2) return true;
            } else {
                m[prefix] = i;
            }
        }
        return false;
    }
};
