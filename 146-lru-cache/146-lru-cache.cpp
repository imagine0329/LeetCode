class LRUCache {
private:
    list<int> l;
    unordered_map<int, int> val;
    unordered_map<int, list<int>::iterator> iter;
    int capacity;
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(val.find(key) == val.end())
            return -1;
        
        list<int>::iterator it = iter[key];
        l.erase(it);
        l.push_front(key);
        iter[key] = l.begin();
        return val[key];
    }
    
    void put(int key, int value) {
        if(val.find(key) != val.end()) {
            list<int>::iterator it = iter[key];
            l.erase(it);
        }
        else if(l.size() == capacity) {
            int erasedKey = l.back();
            l.pop_back();
            val.erase(erasedKey);
            iter.erase(erasedKey);
        }
        
        l.push_front(key);
        val[key] = value;
        iter[key] = l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */