/*
Explanation of why prefixSum works:

Think that if we had an array [1,2,3,4,3]. Normal random pickIndex would pick any index from 0 to 4 with equal probability. But we want that index=1 is picked by 2/13 probability, index=0 with 1/13 probability and so on. (13 is sum of weights). To ensure that one way to think of it if we make a larger array (of size 13) where the values are the indices such that index i is repeated w[i] times then if we do a normal rand on this array then index 0 to 12 will be picked randomly with equal probability. 13 index array -> [0, 1,1, 2,2,2, 3,3,3,3, 4,4,4]. So there is a 3/13 chance of picking 2 as 2 is repeated thrice in the new array.

Now instead of actually constructing this 13 index array, we just know the range of the index of the 13 index array where value = i. Eg:

for index=0, range is {0,0}
index =1, range of indices of the new array is {1,2}
index=2, range={3,5}
index=3, range ={6,9}
index = 4, range = {10,12}
In other words,

index=0, range is <1
index=1, range is <3
index=2, range is <6
index = 3, range is < 10
index = 4, range is < 13
If you notice the above numbers 1,3,6,10,13 - they are cumulative sum.
The reason this happens is because for every range: right = left + (w[i] - 1) and left is (prev right+1). So if we substitute 2nd equation into 1st. right = (prev right)+w[i]; i.e. keep adding prev sum to current weight.

Thus the prefixSum is able to implement this.
*/

// METHOD-1: linear search
class Solution {
    vector<int> prefixSums;
public:
    Solution(vector<int> &w) {
        for (auto n : w)
            prefixSums.push_back(n + (prefixSums.empty() ? 
                0 : prefixSums.back()));
    }

    int pickIndex() {
        // generate a random number in the range of [0, 1]
        float randNum = (float) rand() / RAND_MAX;
        float target =  randNum * prefixSums.back();
        // run a linear search to find the target zone
        for (int i = 0; i < prefixSums.size(); ++i)
            if (target < prefixSums[i])
                return i;
        return prefixSums.size() - 1;
    }
};

// METHOD-2: binary search
/*
For [1,3,4,6] the probablity of choosing index 0 is 1/14, 1 is 3/14, 2 is 4/14 and 3 is 6/14.
Using Prefix sum I have converted the weight vector into a vector v:- [1,1+3, 1+3+4, 1+3+4+6].
In case of random numbers from [0,14), if the number is 0 then I return index 0, if number lies between [1-4) I return index 1, if number lies between [4-8) I return index 2 and if it lies in [8,14) I return index 3.
So, basically I'm returning the index of the upperbound of the random generated number from vector v.
*/
class Solution {
public:
    // time complexity: O(N)
    Solution(vector<int>& w) {
        for (int num: w) {
            if (prefix.empty()) {
                prefix.push_back(num);
            } else {
                prefix.push_back(prefix.back() + num);
            }
        }
    }
    
    // time complexity: O(logN)
    int pickIndex() {
        float random = (float)rand() / RAND_MAX; // random number in [0, 1]
        float target = random * prefix.back(); 
        return upper_bound(prefix.begin(), prefix.end(), target) - prefix.begin(); // binary search
    }
private:
    vector<int> prefix;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
