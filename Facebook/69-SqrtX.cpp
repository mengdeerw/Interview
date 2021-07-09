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

// lintcode 586 - sqrtx II; 要求精确到小数点后12位
// https://www.lintcode.com/problem/586/?_from=collection&fromId=106
/*
二分浮点数与寻常二分不同的是while中变成了whlie(left+eps<right)
注意小数情况，若x<1将右边界扩大到1可避免结果错误（比如0.04=0.2*0.2）如果我们不将x右边界扩大到1，则无法在[0,0.04]的区间范围内找到正解
*/
class Solution {
public:
    /**
     * @param x: a double
     * @return: the square root of x
     */
    double sqrt(double x) {
        // write your code here
        double left = 0, right = x;
        double mid;
        if (right < 1) right = 1;
        while (left + 1e-12 < right) {
            mid = left + (right - left) / 2;
            if (mid * mid < x) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
