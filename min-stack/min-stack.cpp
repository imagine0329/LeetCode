class MinStack {
public:
    stack<pair<int, int>> s;
    
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty())
            s.push(make_pair(val, val));
        else
        {
            pair<int, int> temp = s.top();
            int minimum = min(val, temp.second);
            s.push(make_pair(val, minimum));
        }
    }
    
    void pop() {
        if(s.empty())
            return;
        
        s.pop();
    }
    
    int top() {
        if(s.empty())
            return -1;
        
        return (s.top()).first;
    }
    
    int getMin() {
        pair<int, int> temp = s.top();
        return temp.second;
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