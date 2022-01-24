class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> q;
        for(auto s : sticks)
            q.push(s);
        
        int cost = 0;
        while(q.size() > 1) {
            int x = q.top();
            q.pop();
            int y = q.top();
            q.pop();
            cost += x + y;
            q.push(x + y);
        }
        
        return cost;
    }
};