/*
基本思路是利用减法, 看看被除数可以减去多少次除数.
使用倍增的思想优化, 可以将减法的次数优化到对数时间复杂度.
我们将除数左移一位(或者让它加上自己), 即得到了二倍的除数, 这时一次减法相当于减去了2个除数. 不断倍增, 时间效率很优秀.
与此同时还需要一个变量记录此时的除数是最初的除数的多少倍, 每次减法后都加到结果上即可.
*/
// time complexity: O(log(dividend/divisor))
class Solution {
public:
    /**
     * @param dividend: the dividend
     * @param divisor: the divisor
     * @return: the result
     */
    int divide(int dividend, int divisor) {
        if (divisor == 0) return 0;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        bool is_negative = (dividend < 0 && divisor > 0) || 
                          (dividend > 0 && divisor < 0);
        
        long long result = 0;
        long long Dividend = abs((long long)dividend);
        long long Divisor = abs((long long)divisor);
        while (Dividend >= Divisor) {
            long long temp = Divisor;
            long long cnt = 1;
            while (Dividend >= temp) {
                Dividend -= temp;
                result += cnt;
                cnt <<= 1; // 倍增
                temp <<= 1; // 倍增
            }
        }

        if (is_negative) result = -result;

        if (result < INT_MIN || result > INT_MAX) return INT_MAX;

        return result;
    }
};
