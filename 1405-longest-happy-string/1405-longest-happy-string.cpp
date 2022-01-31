class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> q;
        
        if(a) q.push({a, 'a'});
        if(b) q.push({b, 'b'});
        if(c) q.push({c, 'c'});
        
        string ans;
        while(q.size() > 1) {
            auto curr = q.top(); q.pop();
            auto next = q.top(); q.pop();
            
            ans += curr.second;
            if(--curr.first >= 1) {
                ans += curr.second;
                --curr.first;
            }
            ans += next.second;
            if(--next.first >= 1 && next.first >= curr.first) {
                ans += next.second;
                --next.first;
            }
            
            if(curr.first > 0) q.push(curr);
            if(next.first > 0) q.push(next);
        }
        
        if(!q.empty()) {
            ans += q.top().second;
            if(q.top().first >= 2)
                ans += q.top().second;
        }
        
        return ans;
    }
};