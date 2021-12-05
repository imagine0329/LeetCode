class FirstUnique {
private:
    unordered_map<int, bool> unique;
    queue<int> q;
    
public:
    FirstUnique(vector<int>& nums) {
        for(auto n : nums)
            this->add(n);
    }
    
    int showFirstUnique() {
        int ret = q.front();
        while(!q.empty() && !unique[ret])
        {
            q.pop();
            ret = q.front();
        }
        
        if(!q.empty())
            return q.front();
        
        return -1;
    }
    
    void add(int value) {
        if(unique.find(value) == unique.end())
        {
            unique[value] = true;
            q.push(value);
        }
        else
            unique[value] = false;
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */