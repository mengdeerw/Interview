//https://algo.monster/problems/shopping_patterns
/*
Shoe Monster, a popular shopping website for atheletic shoes, would like to know which shoes are frequently bought together.
When a customer purchases two shoes together, we log an edge between the two products. Three shoes that are interconnected form a triple.
A score for a triple can be calculated by counting the total number of shoes outside the triple that are joined with a shoe inside the triple. This is the product sum.
Find the minimum product sum in the graph, or return -1 if no triples exist.
Input
The input to the function/method consists of four arguments:
int products_nodes: the total number of shoe products for sale. Each shoe is identified by a number from 1 to product_nodes.
int products_from[]: the list of products on the left side of each edges
int products_to[]: the list of products on the right side of each edge

Output
int: the minimum product sum or -1 if no triples exist.

Constraints
There is always at least two products and one edge. All edges are valid, ie. they do not refer to itself, and are a valid product number, ie. between 1 and product_nodes.

Examples
Example 1:
Input:
products_nodes = 6
products_edges = 6
products_from = [1, 2, 2, 3, 4, 5]
products_to = [2, 4, 5, 5, 5, 6]

Product	Related Products
1	2
2	1,4,5
3	5
4	2,5
5	2,3,4,6
6	5
A graph of n = 6 products where the only triple of related products is (2, 4, 5).

Product	Outside Products	Which Products Are Outside
2	1	1
4	0	
5	2	3, 6
In the diagram above, the total product score is 1 + 0 + 2 = 3 for the triple (2, 4, 5).
*/

int shopping_patterns(int products_nodes, std::vector<int> products_from, std::vector<int> products_to) {
    vector<vector<int>> neighbors (products_nodes, vector<int>{});
    for (int i = 0; i < products_from.size(); i++) {
        int u = products_from[i] - 1;
        int v = products_to[i] - 1;
        neighbors[u].push_back(v);
        neighbors[v].push_back(u);
    }
    // all (u, v, w) where
    // - (u, v), (v, w), (u, w) are neighbors (trio)
    // - u < v < w (to avoid duplicates, as optimization)
    int minSum = INT_MAX;
    for (int u = 0; u < neighbors.size(); u++) {
        vector<int> u_neighbor = neighbors[u];
        for (int v: u_neighbor) { 
            if (v < u) continue; // avoid duplicates
            for (int w: u_neighbor) { 
                vector<int> v_neighbor = neighbors[v];
                if (w < u || find(v_neighbor.begin(), v_neighbor.end(), w) == v_neighbor.end()) continue; // not trio
                vector<int> w_neighbor = neighbors[w];
                // each neighbors list include the other 2 in the trio, which we don't count in product score
                int curSum = u_neighbor.size()-2 + v_neighbor.size()-2 + w_neighbor.size()-2;
                minSum = min(minSum, curSum);
            }
        }
    }
    return minSum == INT_MAX ? -1 : minSum;
}
