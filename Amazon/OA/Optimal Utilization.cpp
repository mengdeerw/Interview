/*
Find a pair of entries from two lists that yield a sum that is as close to a target number as possible, without exceeding it.
Each entry in a list is a key-value pair, where the key is a number identifier and the value is also a number. The output must be a list containing the pairs of numbers representing the identifiers that yield the result.
If a solution is not possible, return an empty list.
*/
std::vector<std::vector<int>> get_pairs(std::vector<std::vector<int>> a, std::vector<std::vector<int>> b, int target) {
    // WRITE YOUR BRILLIANT CODE HERE
    vector<vector<int>> result;
    // sort
    auto cmp = [](auto& x, auto& y){
        return x[1] < y[1];
    };
    sort(a.begin(), a.end(), cmp); // O(nlogn)
    sort(b.begin(), b.end(), cmp);
    
    int left = 0, right = b.size() - 1;
    int maxSum = INT_MIN;
    while (left < a.size() && right >= 0) {
        int curSum = a[left][1] + b[right][1];
        if (curSum > target) {
            right--;
        } else {
            if (maxSum <= curSum) {
                if(maxSum <curSum){  // move as close as possible to target
                    maxSum=curSum;
                    result.clear();  // rest res since find new closer pair
                }
                result.push_back({a[left][0], b[right][0]});
                // check duplicate
                int index=right-1;
                while(index>=0 && b[index][1]==b[right][1]){
                    result.push_back({a[left][0],b[index--][0]});
                }
            }
            left++;
        }
    }
    return result;
}
