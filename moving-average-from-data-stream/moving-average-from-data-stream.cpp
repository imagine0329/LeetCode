class MovingAverage {
private:
    int windowSum;
    int windowSize;
    queue<int> q;
    
public:
    MovingAverage(int size) {
        windowSize = size;
        windowSum = 0;
    }
    
    double next(int val) {
        int first;
        if(q.size() == windowSize){
            first = q.front();
            q.pop();
        }
        else
            first = 0;
        
        q.push(val);
        
        windowSum = windowSum - first + val;
        
        return (double)windowSum / (double)q.size();
    }
};


/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */