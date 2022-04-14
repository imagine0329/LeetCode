/*
- sticks = int array
    len of array
    len of stick

- sticks[i] = len of ith stick
- connect 2 sticks into one stick
    cost = s[x] + s[y]
- connect all sticks until 1 stick remaining
- return
    min cost of all connecting

*/

class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> q;
        
        for(auto s : sticks)
            q.push(s);
        
        int cost = 0;
        while(q.size() > 1) {
            int sum = q.top(); q.pop();
            sum += q.top(); q.pop();
            cost += sum;
            q.push(sum);
        }
        
        return cost;
    }
};