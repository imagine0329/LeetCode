class MyCircularQueue {
private:
    vector<int> q;
    int k, front, rear;
    
public:
    MyCircularQueue(int k) {
        this->k = k + 1;
        q = vector<int>(k + 1);
        front = 0, rear = 1;
    }
    
    bool enQueue(int value) {
        if(isFull())
            return false;
        
        q[rear] = value;
        rear = (rear + 1) % k;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        
        int ret = q[(front + 1) % k];
        front = (front + 1) % k;
        return true;
    }
    
    int Front() {
        if(isEmpty())
            return -1;
        
        int idx = (front + 1) % k;
        return q[idx];
    }
    
    int Rear() {
        if(isEmpty())
            return -1;
        
        int idx = rear == 0 ? k - 1 : rear - 1;
        return q[idx];
    }
    
    bool isEmpty() {
        if((front + 1) % k == rear)
            return true;
        return false;
    }
    
    bool isFull() {
        if(front == rear)
            return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */