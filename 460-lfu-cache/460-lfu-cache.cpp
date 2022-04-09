class LFUCache {
private:
    unordered_map<int, int> val;
    unordered_map<int, list<int>> counter;
    unordered_map<int, pair<int, list<int>::iterator>> info;
    int leastFreq;
    int capacity;
    
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->leastFreq = 1;
    }
    
    int get(int key) {
        if(val.find(key) == val.end())
            return -1;
        
        update(key);
        return val[key];
    }
    
    void put(int key, int value) {
        if(!capacity) return;
        if(val.find(key) != val.end()) {
            val[key] = value;
            update(key);
        }
        else {
            if(val.size() == capacity) {
                int removedKey = counter[leastFreq].back();
                counter[leastFreq].pop_back();
                info.erase(removedKey);
                val.erase(removedKey);
            }
            leastFreq = 1;
            val[key] = value;
            counter[leastFreq].push_front(key);
            info[key].first = leastFreq;
            info[key].second = counter[leastFreq].begin();
        }
    }
    
    void update(int key) {
        int cnt = info[key].first;
        list<int>::iterator it = info[key].second;
        
        counter[cnt].erase(it);
        if(cnt == leastFreq && counter[cnt].size() == 0)
            leastFreq++;
        
        cnt++;
        counter[cnt].push_front(key);
        info[key].first = cnt;
        info[key].second = counter[cnt].begin();
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */