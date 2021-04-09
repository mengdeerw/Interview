#include <bits/stdc++.h>
using namespace std;

int find(vector<int>& parents, int i) {
	//cout << "finding.." << endl;
	while (parents[i] != i) { // for root, parents[i] == i
		//parents[i] = parents[parents[i]];
		i = parents[i];
		//cout << "find-i: " << i << endl;
	}
	return i;
}

void getUnion(vector<int>& parents, vector<int>& rank, int node1, int node2) {
	int p1 = find(parents, node1);
	int p2 = find(parents, node2);

	if (p1 == p2) {
		//cout << "p1 == p2" << endl;
		return;
	}
	int p1_rank = rank[p1];
	int p2_rank = rank[p2];
	if (p1_rank > p2_rank) {
		parents[p2] = p1;
		rank[p1] += p2_rank;
	} else if (p1_rank < p2_rank) {
		parents[p1] = p2;
		rank[p2] += p1_rank;
	} else {
		parents[p2] = p1;
		rank[p1] += p2_rank;
	}
}

int connectedSum(int n, vector<string>& edges) {
	vector<int> parents(n + 1);
	vector<int> rank(n + 1);
	// initialize
	for (int i = 1; i < n + 1; i++) {
		parents[i] = i;
		rank[i] = 1;
	}
	// union
	for (auto e: edges) {
		size_t pos = e.find(" ");
		int node1 = stoi(e.substr(0, pos));
		cout << "node1: " << node1 << endl;
		int node2 = stoi(e.substr(pos + 1));
		cout << "node2: " << node2 << endl;
		getUnion(parents, rank, node1, node2);
	}
	// calculate sum
	int result = 0;
	for (int i = 0; i < parents.size(); i++) {
		int cur_parent = parents[i];
		int cur_rank = rank[i];
		if (cur_parent == i) {
			result += ceil(sqrt(cur_rank));
			//cout << "result: " << result << endl;
		}
	}
	return result;
}

int main() {
	vector<string> edges = {"1 2", "1 4"};
	vector<string> edges2 = {"8 1", "5 8", "7 3", "8 6"};
	int result1 = connectedSum(4, edges);
	cout << "result1: " << result1 << endl;
	int result2 = connectedSum(8, edges2);
	cout << "result2: " << result2 << endl;
}
