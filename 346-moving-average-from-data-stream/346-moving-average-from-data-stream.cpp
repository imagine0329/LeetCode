class MovingAverage {
private:
    int size, sum;
    queue<int> q;
    
public:
    MovingAverage(int size) {
        this->size = size;
        sum = 0;
    }
    
    double next(int val) {
        sum += val;
        q.push(val);
        if(q.size() > size) {
            sum -= q.front();
            q.pop();
        }
        
        return (double)sum / q.size();
    }
};


/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */