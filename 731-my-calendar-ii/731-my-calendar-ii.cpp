class MyCalendarTwo {
private:
    vector<pair<int, int>> calendar;
    vector<pair<int, int>> overlaps;
    
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(auto& b : overlaps) {
            if(start < b.second && end > b.first) return false;
        }
        for(auto& b : calendar) {
            if(start < b.second && end > b.first)
                overlaps.push_back({max(start, b.first), min(end, b.second)});
        }
        calendar.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */