// binary search possible answers
// time complexity: 实际处理时不需要记录下整个前缀和数组，只需记录当前的前缀和和左侧最小的前缀和
// O(Nlog(max_nums - min_nums))
/*
1.我们考虑二分平均值，那么我们需要一个check函数，能在O(N)复杂度内判断是否存在一个子数组的平均值大于等于我们二分出来的平均值
2.对于一个平均数ave，我们先将nums数组每个数减去ave，那么只要存在一个长度大于k的子数组和大于等于0，就说明平均数ave可行，这可以在O(N)时间内完成
*/
class Solution {
public:
    /**
     * @param nums: an array with positive and negative numbers
     * @param k: an integer
     * @return: the maximum average
     */
    double findMaxAverage(vector<int> &nums, int k) {
        if (nums.empty()) return 0.0;
        double left = (double)nums[0];
        double right = (double)nums[0];

        for (int i = 0; i < nums.size(); i++) { 
            left = min((double)nums[i], left); // find the min number in nums
            right = max((double)nums[i], right); // find the max number in nums
        }

        while (left + 1e-5 < right) {
            double mid = left + (right - left) / 2;
            if (check(nums, k, mid)) { // mid可行，说明答案大于等于mid
                left = mid;
            } else {
                right = mid;
            }
        }
        return left;
    }
private:
/*
1.将nums数组每个数减去mid
2.求nums数组的前缀和数组pre
3.设置指针index等于k，那么在nums[0:index]中，长度大于k的子数组，区间和最大为pre[index - 1] - min{pre[0 : index - k]}
4.将index不断右移直到指向数组末端，若中间区间和最大值大于等于0，check函数直接返回True，结束后还为返回值则返回False
*/
    bool check(vector<int>& nums, int k, double avg) {
        //rightSum表示当前指向位置的前缀和
        //leftSum表示当前指向位置左侧k个位置的前缀和
        //minLeftSum表示左侧最小的前缀和
        double rightSum = 0, leftSum = 0, minLeftSum = 0;
        for (int i = 0; i < k; i++) {
            rightSum += nums[i] - avg;
        }
        if (rightSum >= 0) return true;
        
        for (int i = k; i <= nums.size(); i++) {
            rightSum += (double)nums[i] - avg;
            leftSum += (double)nums[i - k] - avg;
            minLeftSum = min(minLeftSum, leftSum);
            if (rightSum - minLeftSum >= 0) return true;
        }
        return false;
    }
};
