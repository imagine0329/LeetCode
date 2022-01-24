class FirstUnique {
private:
    list<int> l;
    unordered_map<int, list<int>::iterator> m;
    
public:
    FirstUnique(vector<int>& nums) {
        for(auto n : nums)
            add(n);
    }
    
    int showFirstUnique() {
        return l.empty() ? -1 : l.front();
    }
    
    void add(int value) {
        auto it = m.find(value);
        if(it == m.end()) {
            l.push_back(value);
            m[value] = --l.end();
        }
        else if(it->second != l.end()) {
            l.erase(it->second);
            m[value] = l.end();
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */