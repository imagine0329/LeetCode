class LRUCache {
private:
    unordered_map<int, int> cache;
    unordered_map<int, list<int>::iterator> it;
    list<int> l;
    int capacity;
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end())
            return -1;
        
        l.erase(it[key]);
        l.push_front(key);
        it[key] = l.begin();
        return cache[key];
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()) {
            l.erase(it[key]);
        }
        else {
            if(!cache.empty() && cache.size() == capacity) {
                int lruKey = l.back();
                l.pop_back();
                it.erase(lruKey);
                cache.erase(lruKey);
            }
        }
        
        cache[key] = value;
        l.push_front(key);
        it[key] = l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */