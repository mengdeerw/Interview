// min heap
// time complexity: O(NlogK)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // maintain a min heap with fixed size of k
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num: nums) {
            pq.push(num);
            if (pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};

// max heap
// time complexity: O(NlogN)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // max heap
        priority_queue<int, vector<int>, less<int>> pq;
        for (int num: nums) {
            pq.push(num);
        }
        while (--k) {
            pq.pop();
        }
        return pq.top();
    }
};

// quick sort
// time complexity: average O(n), worst case O(n^2)
class Solution {
public:
    // quick sort: elements>=pivot | pivot | elements<=pivot
    int findKthLargest(vector<int>& nums, int k) { //average O(n), worst case O(n2)
        if(k<1 || k>nums.size()) return -1;
        int start = 0, end = nums.size()-1;
        int pivot, l, r;
        while(1){        
            pivot = nums[start]; l = start; r = end; //set the pivot and checking window

            while(l <= r){
                if(nums[l] >= pivot) l++;
                else if(nums[r] <= pivot) r--;
                else {swap(nums[l], nums[r]);}
            }
            swap(nums[start], nums[r]); //pivot is fixed at index r, which is (r+1)th 

            if(k == r+1) return nums[r];
            else if(k > r+1) start = r+1; //move to pivot's right part
            else {end = r-1;} //move to pivot's left part
        }
    }
};

// another version: quick sort
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left=0, right=nums.size()-1;
        while(true){
            /*** return pivot position ***/
            int pos=help(nums, left, right);
            /** found position **/
            if(pos==k-1)  return nums[pos];
            /** the bigger contains more number **/
            if(pos>k-1)  right=pos-1;
            /** the smaller contains more number **/
            else left=pos+1;
        }
    }
    
    /*** quick-sort-based-pivot-function: return-the-position-of-the-left-element-in-the-partitioned-list ***/
    int help(vector<int>& nums, int left, int right){
        int pivot=nums[left];
        int l=left+1, r=right;
        while(l<=r){
            /*** move the bigger number left and smaller number right ***/
            if(nums[l]<pivot && nums[r]>pivot)   swap(nums[l++], nums[r--]);
            if(nums[l]>=pivot)  l++;
            if(nums[r]<=pivot)  r--;
        }
        /*** swap the pivot ***/
        swap(nums[left], nums[r]);
        return r;
    }
};

// STL sort
// time complexity: O(NlogN)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};
