class FirstUnique {
private:
    unordered_map<int, int> freq;
    queue<int> q;
    
public:
    FirstUnique(vector<int>& nums) {
        for(auto n : nums)
            add(n);
    }
    
    int showFirstUnique() {
        while(!q.empty() && freq[q.front()] != 1)
            q.pop();
        
        return q.empty() ? -1 : q.front();
    }
    
    void add(int value) {
        q.push(value);
        freq[value]++;
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */