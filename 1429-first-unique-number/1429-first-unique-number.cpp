class FirstUnique {
private:
    unordered_map<int, bool> isUnique;
    queue<int> q;
    
public:
    FirstUnique(vector<int>& nums) {
        for(auto n : nums)
            add(n);
    }
    
    int showFirstUnique() {
        while(!q.empty() && !isUnique[q.front()])
            q.pop();
        
        return q.empty() ? -1 : q.front();
    }
    
    void add(int value) {
        if(isUnique.find(value) == isUnique.end()) {
            isUnique[value] = true;
            q.push(value);
        }
        else
            isUnique[value] = false;
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */