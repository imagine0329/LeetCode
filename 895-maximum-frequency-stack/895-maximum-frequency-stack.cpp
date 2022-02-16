class FreqStack {
private:
    int maxFreq;
    unordered_map<int, stack<int>> freqStack;
    unordered_map<int, int> freq;
    
public:
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int val) {
        ++freq[val];
        freqStack[freq[val]].push(val);
        if(freq[val] > maxFreq)
            maxFreq = freq[val];
    }
    
    int pop() {
        int ret = freqStack[maxFreq].top();
        freqStack[maxFreq].pop();
        --freq[ret];
        if(freqStack[maxFreq].empty())
            maxFreq--;
        return ret;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */