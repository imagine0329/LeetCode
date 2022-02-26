class MyCalendarThree {
private:
    map<int, int> m;
    
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        m[start]++;
        m[end]--;
        int booking = 0, largest = 0;
        
        for(auto n : m)
            largest = max(largest, booking += n.second);
        
        return largest;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */