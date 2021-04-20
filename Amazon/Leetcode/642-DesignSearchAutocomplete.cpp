// METHOD-1: trie + priority queue
class TrieNode {
public:
    string str;
    int count;
    unordered_map<char, TrieNode*> child;
    TrieNode(): str(""), count(0) {};
    
    ~TrieNode() {
        for (auto& kv: child) {
            if (kv.second) delete kv.second;
        }
    }
};

// min heap
struct cmp {
    bool operator() (pair<string, int>& a, pair<string, int>& b) {
        return a.second > b.second || a.second == b.second && a.first < b.first;
    }
};

class AutocompleteSystem {
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new TrieNode();
        for (int i = 0; i < sentences.size(); i++) {
            insert(sentences[i], times[i]);
        }
        curNode = root;
        data = "";
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            insert(data, 1);
            // reset
            data.clear();
            curNode = root;
            return {};
        }
        data.push_back(c);
        if (curNode && curNode->child.count(c)) {
            curNode = curNode->child[c]; // already in Trie go to next node
        } else {
            curNode = NULL;
            return {};
        }
        dfs(curNode);
        
        vector<string> result (pq.size());
        for (int i = pq.size() - 1; i >= 0; i--) {
            result[i] = pq.top().first;
            pq.pop();
        }
        return result;
    }
    
    void dfs(TrieNode* node) {
        if (node->str != "") {
            pq.push({node->str, node->count});
            if (pq.size() > 3) pq.pop();
        }
        for (auto& kv: node->child) {
            dfs(kv.second);
        }
    }
    
    void insert(string& s, int count) {
        TrieNode* cur = root;
        for (char& c: s) {
            if (!cur->child.count(c)) {
                cur->child[c] = new TrieNode(); //initialize
            }
            cur = cur->child[c];
        }
        cur->str = s;
        cur->count += count;
    }
    
private:
    TrieNode* root;
    TrieNode* curNode;
    string data;
    priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */

// METHOD-2: priority queue
class AutocompleteSystem {
    unordered_map<string, int> dict;
    string data;

public:
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        for (int i = 0; i < times.size(); i++)
            dict[sentences[i]] += times[i];
        data.clear();
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            dict[data]++;
            data.clear();
            return {};
        }

        data.push_back(c);
        auto cmp = [](const pair<string, int> &a, const pair<string, int> &b) {
            return a.second > b.second || a.second == b.second && a.first < b.first;
        };

        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> pq(cmp);

        for (auto &p : dict) {
            bool match = true;
            for (int i = 0; i < data.size(); i++) {
                if (data[i] != p.first[i]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                pq.push(p);
                if (pq.size() > 3)
                    pq.pop();
            }
        }

        vector<string> res(pq.size());
        for (int i = pq.size() - 1; i >= 0; i--) {
            res[i] = pq.top().first;
            pq.pop();
        }
        return res;
    }
};
