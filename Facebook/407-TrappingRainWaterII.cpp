class Cell {
public:
    int x, y, val;
    Cell(int x_, int y_, int val_) : x(x_), y(y_), val(val_) {} 
};

class Solution {
public:
    /**
     * @param heights: a matrix of integers
     * @return: an integer
     */
    int trapRainWater(vector<vector<int>> &heights) {
        if (heights.size() == 0 || heights[0].size() == 0) return 0;
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // min heap to save the water height
        auto cmp = [](auto& a, auto& b){
            return a.val > b.val;
        };
        priority_queue<Cell, vector<Cell>, decltype(cmp)> pq(cmp);

        //starting from the most outside cells, they cannot hold waters
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
                    pq.push(Cell(i, j, heights[i][j]));
                    visited[i][j] = true;
                }
            }
        }

        int result = 0;
        const vector<vector<int>> dirs {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!pq.empty()) {
            Cell cur = pq.top();
            pq.pop();
            for (auto dir: dirs) {
                int nx = cur.x + dir[0];
                int ny = cur.y + dir[1];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[nx][ny]) continue;
                visited[nx][ny] = true;
                // we need to find out the water height, which means the max height water can reach
                int new_height = max(cur.val, heights[nx][ny]);
                result += new_height - heights[nx][ny];
                pq.push(Cell(nx, ny, new_height));
            }
        }
        return result;
    }
};
