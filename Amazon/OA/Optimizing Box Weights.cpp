/*
Given a multiset (set that allows for multiple instances of same value), partition it into two multisets A and B such that the sum of A is greater than that of B. Return A. If more than one such As exists, return the one with minimal size.
*/
/*
we only need to extract the largest elements in descending order, which seems like a perfect opportunity for a priority queue.
Therefore, we put all the values into a heap through heapify (note: inserting one by one would defeat the purpose, as that would take O(n log n) time which is on the same magnitude as sorting). We then pop one element at a time into a separate array, until the sum of the removed elements is larger than half the total sum. The removed elements are in descending order, so we reverse the result array before returning.
For input of size n and output of size m, this approach takes O(n + m log n) as opposed to O(n log n) by sorting, which is faster in all cases and especially so if the output size is small.
*/
std::vector<int> optimizing_box_weights(std::vector<int> arr) {
    // WRITE YOUR BRILLIANT CODE HERE
    int target = 0;
    priority_queue<int, vector<int>, less<int>> pq; //max heap
    for (int num: arr) {
        target += num;
        pq.push(num);
    }
    target /= 2;
    
    int curSum = 0;
    vector<int> result;
    while (curSum <= target) {
        int val = pq.top();
        pq.pop();
        curSum += val;
        result.push_back(val);
    }
    reverse(result.begin(), result.end());
    return result;
}

