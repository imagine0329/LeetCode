class HitCounter {
private:
    queue<int> hits;
    
    void removeStamp(int timestamp) {
        while(!hits.empty() && hits.front() <= timestamp - 300)
            hits.pop();
    }
    
public:
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        hits.push(timestamp);
        removeStamp(timestamp);
    }
    
    int getHits(int timestamp) {
        removeStamp(timestamp);
        return hits.size();
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */