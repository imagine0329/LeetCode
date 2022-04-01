class Solution {
public:
    int kthFactor(int n, int k) {
        priority_queue<int> q;
        int sqrtN = sqrt(n);
        
        for(int i = 1; i < sqrtN + 1; i++) {
            if(n % i == 0) {
                pushElement(q, i, k);
                if(i != n / i) pushElement(q, n / i, k);
            }
        }
        
        return k == q.size() ? q.top() : -1;
    }
    
    void pushElement(priority_queue<int>& q, int x, int k) {
        q.push(x);
        if(q.size() > k)
            q.pop();
    }
};