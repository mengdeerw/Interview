/*
algorithm: BFS + minHeap
1. the elements on the 4 sides of the matrix can be considered at tentative bars for the bucket
2. maintain a priority queue (min heap) and extract the smallest value (bar) in a loop
3. we also maintain the max value M extracted for the height of the lowest bar
4. while extracting the smallest value, we also visit all the surrounding squares (left, right, up, down)
5. if a visited square has height H smaller than M, then water can be trapped at this square at amount (M-H)
5. this is bc M must be the lowest bar amoung other bars to trap water for this square, since we always visit the lowest element first with the min heap
6. add the water up to get the total amount of water that could be trapped
*/

// Time complexity: O(m*n)
// Space complexity: O(m*n)
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int result = 0;
        int row = heightMap.size(), col = heightMap[0].size();
        int max_height = INT_MIN;
        auto cmp = [](auto const& a, auto const& b){
            return a.first > b.first;
        };
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(cmp)> pq(cmp);
        vector<vector<bool>> visited (row, vector<bool>(col, false));
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (i == 0 || j == 0 || i == row - 1 || j == col - 1) {
                    pq.push({heightMap[i][j], {i, j}});
                    visited[i][j] = true;
                }
            }
        }
        
        vector<vector<int>> dirs {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!pq.empty()) {
            auto top = pq.top(); pq.pop();
            int height = top.first, r = top.second.first, c = top.second.second;
            max_height = max(max_height, height); // update max
            
            for (auto dir: dirs) {
                int new_r = r + dir[0], new_c = c + dir[1];
                if (new_r < 0 || new_r >= row || new_c < 0 || new_c >= col || visited[new_r][new_c]) continue;
                // first update visited
                visited[new_r][new_c] = true;
                // update result;
                if (heightMap[new_r][new_c] < max_height) result += max_height - heightMap[new_r][new_c];
                // do the next pq push
                pq.push({heightMap[new_r][new_c], {new_r, new_c}});
            } 
        }
        return result;
    }
};
