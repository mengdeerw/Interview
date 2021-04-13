// Time complexity: O（1）
// Space complexity: O(prefixes)/ O(N*L^2)
class Trie {
public:
    /** Initialize your data structure here. */
    Trie(): root_(new TrieNode()) {} // root = new TrieNode()

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* p = root_.get(); // unique pointer function
        for (char c: word) {
            if (!p->children[c - 'a']) {
                p->children[c - 'a'] = new TrieNode();
            }
            p = p->children[c - 'a']; //move to next node
        }
        p->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* p = find(word);
        return p && p->is_word;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix) != nullptr;
    }

private:
    struct TrieNode {
        bool is_word;
        vector<TrieNode*> children;
        TrieNode(): is_word(false), children(26, nullptr){}
        
        // desctructor
        ~TrieNode() {
            for (TrieNode* child: children) {
                if (child) delete child;
            }
        }
    };
    
    TrieNode* find(string& prefix) {
        TrieNode* p = root_.get();
        for (char c: prefix) {
            p = p->children[c - 'a'];
            if (p == nullptr) break;
        }
        return p;
    }
    
    std::unique_ptr<TrieNode> root_; // TrieNode*
};

// without unique_ptr
class Trie {
public:
    /** Initialize your data structure here. */
    Trie(): root_(new TrieNode()) {}
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto r = root_;
        for (char c: word) {
            if (!r->children[c - 'a']) {
                r->children[c - 'a'] = new TrieNode();
            }
            r = r->children[c - 'a'];
        }
        r->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto r = find(word);
        return r && r->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto r = find(prefix);
        return r != nullptr;
    }
private:
    struct TrieNode {
        bool is_word;
        vector<TrieNode*> children;
        TrieNode(): is_word(false), children(26, nullptr) {}
        
        ~TrieNode() {
            for (auto child: children) {
                if (child) delete child;
            }
        }
    };
    
    TrieNode* root_;
    
    TrieNode* find(string& word) {
        auto r = root_;
        for (char c: word) {
            r = r->children[c - 'a'];
            if (r == nullptr) break;
        }
        return r;
    }
};
