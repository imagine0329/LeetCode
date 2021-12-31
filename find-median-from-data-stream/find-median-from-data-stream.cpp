class MedianFinder {
private:
    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq;
    double median = 0;
    
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(num > median)
            min_pq.push(num);
        else
            max_pq.push(num);
        
        int m = max_pq.size(), n = min_pq.size();
        if(abs(m-n) > 1)
        {
            if(m > n)
            {
                min_pq.push(max_pq.top());
                max_pq.pop();
                m--;
                n++;
            }
            else
            {
                max_pq.push(min_pq.top());
                min_pq.pop();
                m++;
                n--;
            }
        }
        
        if((m + n) % 2)
        {
            if(m > n)
                median = max_pq.top();
            else
                median = min_pq.top();
        }
        else
            median = (double)(min_pq.top() + max_pq.top()) / 2;
        
    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */