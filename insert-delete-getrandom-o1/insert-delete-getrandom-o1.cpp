class RandomizedSet {
private:
    unordered_map<int, int> m;
    vector<int> v;
    
    bool find(int val)
    {
        return m.find(val) != m.end();
    }
    
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(find(val))
            return false;
        
        size_t n = m.size();
        v.push_back(val);
        m[val] = n;
        return true;
    }
    
    bool remove(int val) {
        if(!find(val))
            return false;
        
        int last = v.back();
        m[last] = m[val];
        v[m[val]] = v.back();
        v.pop_back();
        m.erase(val);
        
        return true;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
    
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */