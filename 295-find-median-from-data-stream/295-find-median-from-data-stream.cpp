class MedianFinder {
private:
    priority_queue<int> max_q;
    priority_queue<int, vector<int>, greater<int>> min_q;
    
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        min_q.push(num);
        max_q.push(min_q.top());
        min_q.pop();
        
        if(min_q.size() < max_q.size()) {
            min_q.push(max_q.top());
            max_q.pop();
        }
    }
    
    double findMedian() {
        return min_q.size() > max_q.size() ? min_q.top() : (min_q.top() + max_q.top()) * 0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */