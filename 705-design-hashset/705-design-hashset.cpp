class MyHashSet {
private:
    int capacity, m_size;
    double load_factor;
    vector<list<int>> table;
    
    int hash(int key) {
        return key % capacity;
    }
    
    list<int>::iterator search(int key) {
        int h = hash(key);
        return find(table[h].begin(), table[h].end(), key);
    }
    
    void rehash() {
        m_size = 0;
        capacity = max(2, capacity);
        vector<list<int>> old(move(table));
        table = vector<list<int>>(capacity);
        
        for(auto& chain : old) {
            for(auto& key : chain)
                add(key);
        }
    }
    
public:
    MyHashSet() {
        m_size = 0;
        capacity = 2;
        load_factor = 0.75;
        table = vector<list<int>>(capacity);
    }
    
    void add(int key) {
        if(contains(key)) return;
        
        m_size++;
        int h = hash(key);
        table[h].push_back(key);
        if(m_size >= load_factor * capacity) {
            capacity *= 2;
            rehash();
        }
    }
    
    void remove(int key) {
        int h = hash(key);
        auto it = search(key);
        if(it == table[h].end()) return;
        
        m_size--;
        table[h].erase(it);
        if(m_size <= 0.5 * load_factor * capacity) {
            capacity /= 2;
            rehash();
        }
    }
    
    bool contains(int key) {
        int h = hash(key);
        return search(key) != table[h].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */