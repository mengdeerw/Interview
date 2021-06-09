// METHOD-1: min heap
/* construct a min heapeach time 
1. we start at the left top element, each time add the right and down neighbor of current element in to the heap
2. pop k - 1 times then we have the kth smallest element in the matrix
*/
// time complexity: O(X + KlogX) where X = min(K, N), N is the height/width of the matrix
// space complexity: O(X)

class Node {
public:
    int x_;
    int y_;
    int val_;
    
    Node(int x, int y, int val) {
        x_ = x;
        y_ = y;
        val_ = val;
    }
};

class NodeCompare {
public:   
    bool operator() (const Node& a, const Node& b){
        return a.val_ > b.val_;
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        vector<int> dx {0, 1};
        vector<int> dy {1, 0};
        
        priority_queue<Node, vector<Node>, NodeCompare> pq;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        pq.push(Node(0, 0, matrix[0][0]));
        visited[0][0] = true;
        
        while (--k > 0) {
            Node cur = pq.top();
            pq.pop();
            
            for (int i = 0; i < 2; i++) {
                int new_x = cur.x_ + dx[i];
                int new_y = cur.y_ + dy[i];
                if (new_x >= n || new_y >= n || visited[new_x][new_y]) continue;
                Node new_node = Node(new_x, new_y, matrix[new_x][new_y]);
                visited[new_x][new_y] = true;
                pq.push(new_node);
            }
        }
        return pq.top().val_;
    }
};

// METHOD-2: binary search
// 1. do binary search to find the middle element X (not necessarily existing in the matrix)
// 2. count how many elements in the matrix are smaller or equal to X
//    1) record the biggest number smaller than or equal to X as L
//    2) record the smallest number bigger than X as R
// 3. if the count is equal to K, return L;
//    if the count is less than K, update start = R and repeat search
//    if the count is greater than K, update end = L and repeat search

// time complexity: O(Nlog(Max - Min))
// space complexity: O(1)

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int start = matrix[0][0], end = matrix[n - 1][n - 1];
        while (start < end) {
            int mid = start + (end - start) / 2;
            int L = matrix[0][0], R = matrix[n - 1][n - 1];
            int count = countLessEqual(matrix, mid, L, R);
            if (count == k) return L;
            if (count < k) start = R;
            if (count > k) end = L;
        }
        return start;
    }
    
private:
    int countLessEqual(vector<vector<int>>& matrix, int mid, int& L, int& R) {
        int count = 0;
        int n = matrix.size();
        // we start from the bottom left corner
        int row = n - 1, col = 0;
        while (row >= 0 && col < n) {
            if (matrix[row][col] > mid) {
                // record the smallest number greater than mid
                R = min(R, matrix[row][col]);
                row--;
            } else {
                // record the biggest number smaller or equal than mid
                L = max(L, matrix[row][col]);
                count += row + 1;
                col++;
            }
        }
        return count;
    }
};

// binary search version2
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int start = matrix[0][0], end = matrix[n - 1][n - 1];
        int mid;
        while (start < end) {
            int mid = start + (end - start) / 2;
            int count = 0;
            int j = n - 1;
            for (int i = 0; i < n; i++) {
                while (j >= 0 && matrix[i][j] > mid) j--;
                count += j + 1;
            }
            if (count < k) start = mid + 1;
            else end = mid;
        }
        return start;
    }
};
