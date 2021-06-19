// METHOD-1: DFS
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        for (int i = 0; i < equations.size(); i++) {
            string A = equations[i][0];
            string B = equations[i][1];
            double weight = values[i];
            graph[A][B] = weight; // A/B 
            graph[B][A] = 1.0 / weight; // B/A
        }
        
        vector<double> result;
        for (auto query: queries) {
            string X = query[0];
            string Y = query[1];
            if (!graph.count(X) || !graph.count(Y)) {
                result.push_back(-1.0);
                continue;
            }
            unordered_set<string> visited;
            double ans = divide(X, Y, graph, visited);
            result.push_back(ans);
        }
        return result;
    }

private:
    double divide(string& A, string& B, unordered_map<string, unordered_map<string, double>>& graph, unordered_set<string>& visited) {
        if (A == B) return 1.0;
        visited.insert(A);
        for (auto kv: graph[A]) {
            string C = kv.first;
            if (visited.count(C) != 0) continue;
            double value = divide(C, B, graph, visited); // value = C / B
            if (value > 0) 
                return value * graph[A][C]; // A/B = C/B * A/C
        }
        return -1.0;
    }
};

// METHOD-2: Union find
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, pair<string, double>> parents;
        
        for (int i = 0; i < equations.size(); i++) {
            string A = equations[i][0];
            string B = equations[i][1];
            double k = values[i];
            if (!parents.count(A) && !parents.count(B)) {
                parents[A] = {B, k};
                parents[B] = {B, 1.0};
            } else if (!parents.count(A)) {
                parents[A] = {B, k};
            } else if (!parents.count(B)) {
                parents[B] = {A, 1.0 / k};
            } else {
                auto rA = find(A, parents);
                auto rB = find(B, parents);
                parents[rA.first] = {rB.first, k / rA.second * rB.second};
            }
        }
        
        vector<double> result;
        for (auto query: queries) {
            string X = query[0];
            string Y = query[1];
            if (!parents.count(X) || !parents.count(Y)) {
                result.push_back(-1.0);
                continue;
            }
            auto rX = find(X, parents); // {rX, X/rX}
            auto rY = find(Y, parents); // {rY, Y/rY}
            if (rX.first != rY.first) {
                result.push_back(-1.0);
            } else { // X/Y = (X/rX / (Y/rY))
                result.push_back(rX.second / rY.second);
            }
        }
        return result;
    }
    
    pair<string, double> find(string& C, unordered_map<string, pair<string, double>>& parents) {
        if (C != parents[C].first) {
            auto p = find(parents[C].first, parents);
            parents[C].first = p.first;
            parents[C].second *= p.second;
        }
        return parents[C];
    }
};
