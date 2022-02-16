class FreqStack {
private:
    stack<int> maxFreq;
    unordered_map<int, stack<int>> freqStack;
    unordered_map<int, int> freq;
    
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        ++freq[val];
        freqStack[freq[val]].push(val);
        if(maxFreq.empty() || freq[val] > maxFreq.top())
            maxFreq.push(freq[val]);
    }
    
    int pop() {
        int ret = freqStack[maxFreq.top()].top();
        freqStack[maxFreq.top()].pop();
        --freq[ret];
        if(freqStack[maxFreq.top()].empty())
            maxFreq.pop();
        return ret;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */