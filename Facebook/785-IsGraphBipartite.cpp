// coloring with DFS
// Idea: coloring a node with green if it is part of the first set, or red if it is the part of the second set.
// the graph should be bipartite if all the neighbors of one green node are red, or vice versa.

/* for each node:
1. if the node hasn't been visited(changed the color), color it and use opposite color to color its neighors
2. if the node has been visited, recursively check if its current color is the same as the color that is going to be used to color it.
*/
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(); // number of nodes in total
        // 0: yellow; 1: green; -1: red
        // initialize the color with yellow, meaning unvisited
        vector<int> colors(n, 0);
        
        // check for unconnected graph
        for (int i = 0; i < n; i++) {
            if (colors[i] == 0 && !validColor(graph, colors, 1, i)) {
                return false;
            }
        }
        return true;
    }
    
private:
    bool validColor(vector<vector<int>>& graph, vector<int>& colors, int color, int node) {
        if (colors[node] != 0) { // node already been visited
            return color == colors[node];
        }
        
        // for unvisited nodes
        colors[node] = color;
        for (int neighbor: graph[node]) {
            if (!validColor(graph, colors, -color, neighbor)) { // recursively check with opposite colors for neighbors
                return false;
            }
        }
        return true;
    }
};

// BFS
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors (n, 0);
        
        for (int i = 0; i < n; i++) {
            if (colors[i] != 0) continue;
            queue<int> q;
            q.push(i);
            colors[i] = 1; // 1:green; -1:red
            
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                for (int neighbor: graph[cur]) {
                    if (colors[neighbor] == 0) { // unvisited nodes
                        colors[neighbor] = -colors[cur];
                        q.push(neighbor);
                    } else if (colors[neighbor] != -colors[cur]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
