class MaxStack {
private:
    list<int> dll;
    map<int, vector<list<int>::iterator>, greater<int>> m;
    
public:
    MaxStack() {
        
    }
    
    void push(int x) {
        dll.push_front(x);
        m[x].push_back(dll.begin());
    }
    
    int pop() {
        int x = dll.front();
        dll.pop_front();
        m[x].pop_back();
        if(m[x].empty())
            m.erase(x);
        
        return x;
    }
    
    int top() {
        return dll.front();
    }
    
    int peekMax() {
        return m.begin()->first;
    }
    
    int popMax() {
        int x = m.begin()->first;
        auto it = m[x].back(); m[x].pop_back();
        dll.erase(it);
        if(m[x].empty())
            m.erase(x);
        return x;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */