class MedianFinder {
private:
    multiset<int> store;
    multiset<int>::iterator mid;
    
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int n = store.size();
        store.insert(num);
        
        if(!n)
            mid = store.begin();
        else if(num < *mid)
            mid = n & 1 ? mid : prev(mid);
        else
            mid = n & 1 ? next(mid) : mid;
    }
    
    double findMedian() {
        int n = store.size();
        return (double)(*mid + *next(mid, n % 2 - 1)) * 0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */