class MedianFinder {
private:
    multiset<int> data;
    multiset<int>::iterator mid;
    
public:
    MedianFinder() : mid(data.end()){
        
    }
    
    void addNum(int num) {
        int n = data.size();
        data.insert(num);
        
        if(!n)
            mid = data.begin();
        else if(num < *mid)
            mid = n & 1 ? prev(mid) : mid;
        else
            mid = n & 1 ? mid : next(mid);
    }
    
    double findMedian() {
        int n = data.size();
        if(n & 1)
            return *mid;
        else
            return (*mid + *next(mid)) * 0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */