/*
You have a paper box with dividers for holding wine bottles.
The box is divided by m x n dividers into (m + 1) x (n + 1) cells. Assuming the depth of the box is 1, each cell has a volume of 1.
Now we want to remove a number of dividers. Find the largest space after removing the dividers.
*/
/*
You may have already noticed that the largest volume is length of the largest horizontal gap multiplied by the length of the largest vertical gap. There are a few ways to find the largest gap in each direction:

Naively, we can make a boolean array holding the presence of the separator at each index, and then iterate through it to find the largest gap. This requires both O(n) auxiliary space and O(n) time for n separators. (Note: n here is the value, not size, of input! See pseudo-polynomial).

However, since we are provided with the indices of separators that are removed, it suggests that the removed separators may be sparse. Therefore, to reduce the space (but not time) complexity of the above approach, we can use a set to store the removed separators. This would use O(|h|) space, where |h| is the size of the input array h, and |h| <= n since you can't remove more separators than the total number of them.

To further improve the solution: If we have a sorted array of all removed separators, then we don't need to traverse through 1..n to find the consecutive ones, we can simply go through the sorted array. Sorting the array takes O(|h| * log(|h|)) time, and going through the sorted array to find the largest gap takes O(|h|) time. The auxiliary space required is constant if we modify the input arrays; otherwise O(|h|) is needed to store the sorted values. Note that if the input array h is already sorted, this is a strictly better solution. If not, it will depend on the size of h and the value of n. The less percentage of the separators removed (i.e. the more sparse the "removed separators" are), the more efficient this approach is compared to the previous one.

Below we present the solution using the last approach, i.e. sorting and going through the array. This approach is not much slower in the worst case, but much faster in many other cases.
*/

int longest(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int last = -1, consec = 0, max_consec = 0;
    for (int num: arr) {
        if (num != last + 1) {
            consec = 0; // reset
        }
        last = num;
        consec++;
        max_consec = max(max_consec, consec);
    }
    return max_consec;
}

int storage_optimization(int n, int m, std::vector<int> h, std::vector<int> v) {
    // WRITE YOUR BRILLIANT CODE HERE
    return (longest(h) + 1) * (longest(v) + 1);
}
