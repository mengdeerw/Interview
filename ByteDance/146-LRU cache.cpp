class LRUCache {
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
    }
    
    int get(int key) {
        auto it = m_.find(key);
        if (it == m_.end()) return -1;
        
        // if found: update, move key into front
        cache_.splice(cache_.begin(), cache_, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = m_.find(key);
        
        // if already exists: update value of m_[key] and cache_
        if (it != m_.end()) {
            it->second->second = value;
            cache_.splice(cache_.begin(), cache_, it->second);
            return;
        }
        // before inserting, check if reach max capacity
        if (cache_.size() == capacity_) {
            auto old_pair = cache_.back();
            cache_.pop_back();
            m_.erase(old_pair.first);
        }
        // not found, insert into cache_ and update m_
        cache_.push_front({key, value});
        m_[key] = cache_.begin();
    }

private:
    int capacity_;
    list<pair<int, int>> cache_;
    unordered_map<int, list<pair<int, int>>::iterator> m_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
