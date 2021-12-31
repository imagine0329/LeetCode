class FreqStack {
private:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> group;
    int max_freq = 0;
    
public:
    FreqStack() {
    }
    
    void push(int val) {
        int f = ++freq[val];
        if(f > max_freq)
            max_freq = f;
        
        group[f].push(val);
    }
    
    int pop() {
        int ret = group[max_freq].top();
        group[max_freq].pop();
        
        freq[ret]--;
        if(group[max_freq].empty())
            max_freq--;
        
        return ret;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */