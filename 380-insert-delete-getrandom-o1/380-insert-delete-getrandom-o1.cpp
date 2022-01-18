class RandomizedSet {
private:
    unordered_set<int> s;
    
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        return s.insert(val).second;
    }
    
    bool remove(int val) {
        return s.erase(val) != 0;
    }
    
    int getRandom() {
        int idx = rand() % s.size();
        auto it = next(s.begin(), idx);
        
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */