// greedy
// time complexity: O(N)
// space complexity: O(26)
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> last(26, 0);
        // build the map of last occurance of each char
        for (int i = 0; i < S.length(); i++) {
            last[S[i] - 'a'] = i;
        }
        
        int start = 0, end = 0;
        vector<int> result;
        for (int i = 0; i < S.length(); i++) {
            end = max(end, last[S[i] - 'a']);
            if (end == i) {
                result.push_back(end - start + 1);
                start = i + 1; // start position of each label
            }
        }
        return result;
    }
};

// Solution 0: Brute Force
// Time complexity: O(n^2)
// Space complexity: O(1)
class Solution {
public:
    vector<int> partitionLabels(string S) {
      vector<int> ans;
      size_t start = 0;
      size_t end = 0;
      for (size_t i = 0; i < S.size(); ++i) {
        end = max(end, S.find_last_of(S[i]));
        if (i == end) {
          ans.push_back(end - start + 1);
          start = end + 1;
        }
      }
      return ans;
    }
};
