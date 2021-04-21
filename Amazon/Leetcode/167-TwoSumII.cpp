// binary search
// time complexity: O(NlogN)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for (int i = 0; i < n; i++) {
            int l = 0, r = n - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (numbers[mid] == target - numbers[i]) {
                    if (mid == i) l = mid + 1;
                    else return {i + 1, mid + 1};
                } else if (numbers[mid] < target - numbers[i]) 
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return {};
    }
};

// binary search
// time complexity: O(NlogN)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for (int i = 0; i < n; i++) {
            int l = 0, r = n - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (numbers[mid] == target - numbers[i]) {
                    if (mid == i) l = mid + 1;
                    else return {i + 1, mid + 1};
                } else if (numbers[mid] < target - numbers[i]) 
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return {};
    }
};
