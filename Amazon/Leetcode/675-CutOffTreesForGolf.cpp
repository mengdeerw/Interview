// time complexity: O(M^2*N^2)
// space complexity: O(MN)
// Greedy + Shortest path: Identify and sort the trees by its heights, then find shortest paths between
class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        if (forest.empty() || forest[0].empty()) return 0;
        int m = forest.size(), n = forest[0].size();
        vector<vector<int>> trees; // {{height, x, y},...}
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (forest[i][j] > 1)
                    trees.push_back({forest[i][j], i, j});
            }
        }
        
        // sort by trees' heights
        sort(trees.begin(), trees.end());
        
        int result = 0;
        int r = 0, c = 0;
        for (int i = 0; i < trees.size(); i++) {
            int dest_r = trees[i][1];
            int dest_c = trees[i][2];
            int step = BFS(forest, r, c, dest_r, dest_c);
            if (step == -1) return -1;
            
            // Cut the tree, not necessary
            //forest[dest_r][dest_c] = 1;
            
            result += step;
            // set next location
            r = dest_r;
            c = dest_c;
        }
        return result;
    }
    
private:
    // min steps to go from (r,c) to (rr,cc) based on current map
    int BFS(vector<vector<int>>& forest, int r, int c, int rr, int cc) {
        int m = forest.size(), n = forest[0].size();
        queue<pair<int, int>> q;
        q.push({r, c});
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[r][c] = true; //no need
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        int step = 0;
        while (!q.empty()) {      
            int new_nodes = q.size();
            while (new_nodes--) {
                auto node = q.front();
                q.pop();
                int row = node.first;
                int col = node.second;
                // found path
                if (row == rr && col == cc) return step;
                
                for (int i = 0; i < 4; i++) {
                    int new_r = row + dirs[i][0];
                    int new_c = col + dirs[i][1];
                    if (new_r < 0 || new_c < 0 || new_r == m || new_c == n 
                        || !forest[new_r][new_c] || visited[new_r][new_c]) continue;                    
                    
                    visited[new_r][new_c] = true;
                    q.push({new_r, new_c});
                }
            }
            step++;
        }
        return -1;
    }
};
