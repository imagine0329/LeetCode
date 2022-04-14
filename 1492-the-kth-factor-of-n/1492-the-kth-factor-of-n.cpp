class Solution {
public:
    int kthFactor(int n, int k) {
        int sq = sqrt(n);
        priority_queue<int> q;
        
        for(int i = 1; i <= sq; i++) {
            if(n % i == 0) {
                pushFactor(q, i, k);
                
                if(i != n / i)
                    pushFactor(q, n / i, k);
            }
        }
        
        return q.size() < k ? -1 : q.top();
    }
    
    void pushFactor(priority_queue<int>& q, int x, int k) {
        q.push(x);
        if(q.size() > k)
            q.pop();
    }
};