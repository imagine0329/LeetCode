class MinStack {
private:
    stack<int> s;
    stack<pair<int, int>> min_s;
    
public:
    
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(min_s.empty() || val < min_s.top().first)
            min_s.push({val, 1});
        else if(val == min_s.top().first)
            min_s.top().second++;
    }
    
    void pop() {
        int val = s.top();
        s.pop();
        
        if(val == min_s.top().first)
            min_s.top().second--;
        if(min_s.top().second == 0)
            min_s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min_s.top().first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */