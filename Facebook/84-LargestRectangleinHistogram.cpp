// two pointers
// time complexity: O(N^2)
class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();
        if (n == 0) return 0;
        if (n == 1) return heights[0];
        
        int area = INT_MIN;
        int l, r;
        
        for (int i = 0; i < n; ++i) {
            l = i;
            r = i;
            while (l - 1 >= 0 && heights[l - 1] >= heights[i]) {
                l--;
            }
            while (r + 1 <= n - 1 && heights[r + 1] >= heights[i]) {
                r++;
            }
            area = max(area, (r - l + 1) * heights[i]);
        }
        return area;
    }
};

/*
单调栈做法：
1.首先在数组最后加一个0，方便它能保证把入栈的所有数都pop出来、都分析一遍；
2.然后循环数组，如果循环到的数比栈顶的数还大，就直接入栈，因为它在栈里的下面一个数就是它的左边界，比他小嘛；
3.如果循环到的数不比栈顶的数大，则不停地从栈中剔除成员、并对每一个成员进行分析。怎么分析呢？首先当前循环到的数一定是pop成员右边第一个比其小的数，右边界定了，然后根据2可知，它下面的那个数就是它的左边界。左右边界已定，面积可知！
4.特殊处理的是，如果要pop某个成员、而且它是栈中最后一个成员，则右边界即是 pos = -1 的位置，即从数组的最左边到该成员、没有成员比他还小了。
*/
class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();
        if (n == 0) return 0;
        stack<int> st; // save index (for calculating the area)
        int result = 0;
        for (int i = 0; i <= n; i++) {
            int cur = (i == n) ? -1 : heights[i]; // consider case [1,2,3,4,5]

            while (!st.empty() && cur <= heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int left = st.empty() ? 0 : (st.top() + 1);
                int right = i - 1;
                int area = (right - left + 1) * height;
                result = max(result, area);
            }
            st.push(i);
        }
        return result;
    }
};

