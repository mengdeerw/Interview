// prefix sum + hash table(map)
// What needs to happen here is that the dictionary shouldn't just store the remainder, 
// but the times we've seen that remainder in the past.
// calculate modulo: consider negative numbers, need to do (x % K + K) % K
// e.g. x = -12, K = 5, modulo = (-12 % 5 + 5) % 5 = 3.
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        vector<int> freq (K); // count the times that prefix sum is with modulo 0
        freq[0] = 1;
        int prefix = 0, result = 0;
        for (int a: A) {
            prefix = (prefix + a%K + K) % K;
            result += freq[prefix]++;
        }
        return result;
    }
};

// another version
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        vector<int> freq (K);
        freq[0] = 1;
        int prefix = 0, result = 0;
        for (int a: A) {
            prefix += a;
            int remainder = prefix % K;
            if (remainder < 0) remainder += K;
            result += freq[remainder];
            freq[remainder]++;
        }
        return result;
    }
};
