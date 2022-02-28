class MyQueue {
private:
    stack<int> s1, s2;
    
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        move();
        int ret = s2.top(); s2.pop();
        return ret;
    }
    
    int peek() {
        move();
        return s2.top();
    }
    
    bool empty() {
        move();
        return s2.empty();
    }
    
    void move() {
        if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */