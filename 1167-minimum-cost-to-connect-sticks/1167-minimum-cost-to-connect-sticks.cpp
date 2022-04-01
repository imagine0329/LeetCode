class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> q;
        int cost = 0;
        
        for(auto stick : sticks)
            q.push(stick);
        
        while(q.size() > 1) {
            int sum = q.top(); q.pop();
            sum += q.top(); q.pop();
            cost += sum;
            q.push(sum);
        }
        
        return cost;
    }
};