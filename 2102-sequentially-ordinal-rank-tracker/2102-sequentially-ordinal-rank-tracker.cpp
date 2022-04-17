struct compare_max {
    bool operator()(pair<int, string>& a, pair<int, string>& b) {
        if(a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    }
};

struct compare_min {
    bool operator()(pair<int, string>& a, pair<int, string>& b) {
        if(a.first == b.first)
            return a.second < b.second;
        return a.first > b.first;
    }
};

class SORTracker {
private:
    int count = 1;
    priority_queue<pair<int, string>, vector<pair<int, string>>, compare_max> maxHeap;
    priority_queue<pair<int, string>, vector<pair<int, string>>, compare_min> minHeap;
    
public:
    SORTracker() {
        
    }
    
    void add(string name, int score) {
        minHeap.push({score, name});
        if(minHeap.size() > count) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    string get() {
        auto ret = minHeap.top();
        if(!maxHeap.empty()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        count++;
        return ret.second;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */