class MovingAverage {
private:
    int size, sum, count, head;
    vector<int> list;
    
public:
    MovingAverage(int size) {
        this->size = size;
        sum = 0;
        count = 0;
        head = 0;
        list = vector<int>(size, 0);
    }
    
    double next(int val) {
        count = ((count + 1) > size) ? size : ++count;
        
        int tail = (head + 1) % size;
        sum += val - list[tail];
        head = tail;
        list[head] = val;
        return (double)sum / count;
    }
};


/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */