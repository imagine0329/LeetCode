class HitCounter {
private:
    queue<pair<int, int>> hits;
    int total;
    
    void removeStamp(int timestamp) {
        while(!hits.empty() && hits.front().first <= timestamp - 300) {
            total -= hits.front().second;
            hits.pop();
        }
    }
    
public:
    HitCounter() {
        this->total = 0;
    }
    
    void hit(int timestamp) {
        if(hits.empty() || hits.back().first != timestamp)
            hits.push({timestamp, 1});
        else
            hits.back().second++;
        
        this->total++;
    }
    
    int getHits(int timestamp) {
        removeStamp(timestamp);
        return this->total;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */