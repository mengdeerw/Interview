/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

/*
To avoid getting stuck in a loop we would need some way to keep track of the nodes which have already been copied.
By doing this we don't end up traversing them again.
*/
// DFS
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }
        // clone
        Node* clone = new Node(node->val, {});
        visited[node] = clone;
        
        for (Node* neighbor: node->neighbors) {
            clone->neighbors.push_back(cloneGraph(neighbor));
        }
        return clone;
    }
private:
    unordered_map<Node*, Node*> visited;
};

// BFS
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        
        queue<Node*> q;
        q.push(node);
        visited[node] = new Node(node->val, {});
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            for (Node* neighbor: curr->neighbors) {
                if (visited.find(neighbor) == visited.end()) {
                    visited[neighbor] = new Node(neighbor->val, {});
                    q.push(neighbor);
                }
                visited[curr]->neighbors.push_back(visited[neighbor]);
            }
        }
        return visited[node];
    }
private:
    unordered_map<Node*, Node*> visited;
};
