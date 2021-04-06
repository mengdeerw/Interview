// leetcode 1041
class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0;
        int index = 0; // facing north
        
        // N - 0; E - 1; S - 2; W - 3;
        vector<vector<int>> dirs {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        for (char c: instructions) {
            if (c == 'G') {
                x += dirs[index][0];
                y += dirs[index][1];
            } else if (c == 'L') { // west
                index = (index + 3) % 4;
            } else { // east
                index = (index + 1) % 4;
            }
        }
        
        // if robot returns into initial position or robot does not face north
        return (x == 0 && y == 0) || (index != 0);
    }
};
