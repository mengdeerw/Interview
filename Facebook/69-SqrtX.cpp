// 二分答案法
// time complexity: O(logN)
class Solution {
public:
    int mySqrt(int x) {
        assert(x >= 0);
        if (x <= 1) return x;
        
        int start = 1, end = x;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (mid == x / mid) return mid;
            else if (mid < x / mid) { // x > mid * mid
                start = mid;
            } else end = mid;
        }
        // @here start + 1 == end
        if (end <= x / end) return end;
        return start;
    }
};

// brute force
// time complexity: O(N)
class Solution {
public:
    int mySqrt(int x) {
        assert(x >= 0);
        if (x <= 1) return x;
        
        int i;
        for (i = 1; i < x; i++) {
            if (i == x / i) return i;
            else if (i > x / i) return i - 1;
        }
        return i - 1;
    }
};

// math: sqrt(x) == e^(1/2 * logx)
// time complexity: O(1)
class Solution {
public:
    int mySqrt(int x) {
        assert(x >= 0);
        if (x <= 1) return x;
        
        int left = (int)pow(M_E, 0.5 * log(x));
        int right = left + 1;
        return (long) right * right > x ? left : right;
    }
};
