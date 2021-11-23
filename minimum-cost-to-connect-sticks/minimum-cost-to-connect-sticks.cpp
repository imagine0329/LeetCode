class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        if(sticks.size() < 2)
            return 0;
        
        priority_queue<int, vector<int>, greater<int>> q;
        int cost = 0, s1, s2;
        
        for(auto i : sticks)
            q.push(i);
        
        while(q.size() > 1)
        {
            s1 = q.top();
            q.pop();
            s2 = q.top();
            q.pop();
            q.push(s1+s2);
            cost += (s1 + s2);
        }
        
        return cost;
    }
};