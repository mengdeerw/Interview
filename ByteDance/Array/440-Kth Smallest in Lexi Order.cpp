/*
我们如果仔细观察字典顺序的数组，我们可以发现，其实这是个十叉树Denary Tree，就是每个节点的子节点可以有十个，比如数字1的子节点就是10到19，数字10的子节点可以是100到109，但是由于n大小的限制，构成的并不是一个满十叉树。我们分析题目中给的例子可以知道，数字1的子节点有4个(10,11,12,13)，而后面的数字2到9都没有子节点，那么这道题实际上就变成了一个先序遍历十叉树的问题，那么难点就变成了如何计算出每个节点的子节点的个数，我们不停的用k减去子节点的个数，当k减到0的时候，当前位置的数字即为所求。现在我们来看如何求子节点个数，比如数字1和数字2，我们要求按字典遍历顺序从1到2需要经过多少个数字，首先把1本身这一个数字加到step中，然后我们把范围扩大十倍，范围变成10到20之前，但是由于我们要考虑n的大小，由于n为13，所以只有4个子节点，这样我们就知道从数字1遍历到数字2需要经过5个数字，然后我们看step是否小于等于k，如果是，我们cur自增1，k减去step；如果不是，说明要求的数字在子节点中，我们此时cur乘以10，k自减1，以此类推，直到k为0推出循环，此时cur即为所求
*/
class Solution {
public:
    int findKthNumber(int n, int k) {
        k--;
        int curr = 1;
        while (k > 0) {
            int steps = calcSteps(n, curr, curr + 1); //calculate the interval steps between '1'&'2'
            if (steps <= k) { // found in current range, decrease k until it is less than 0
                k -= steps;
                curr++;
            } else { // not found in current range, increase '1' to '10' and repeat above steps
                curr *= 10;
                k -= 1;
            }
        }
        return curr;
    }
    
    int calcSteps(long long int n, long long int n1, long long int n2) {
        int steps = 0;
        while (n1 <= n) {
            steps += min(n + 1, n2) - n1; // how many numbers between '1' & '2' 
            n1 *= 10;
            n2 *= 10;
        }
        return steps;
    }
};
