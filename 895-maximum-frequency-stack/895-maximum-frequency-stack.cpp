class FreqStack {
private:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> group;
    int max_freq;
    
public:
    FreqStack() {
        max_freq = 0;
    }
    
    void push(int val) {
        ++freq[val];
        if(freq[val] > max_freq)
            max_freq = freq[val];
        
        group[freq[val]].push(val);
    }
    
    int pop() {
        int x = group[max_freq].top();
        group[max_freq].pop();
        --freq[x];
        if(group[max_freq].size() == 0)
            max_freq--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */