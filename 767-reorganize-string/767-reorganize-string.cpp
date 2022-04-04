class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> m;
        priority_queue<pair<int, char>> q;
        
        for(auto c : s)
            m[c]++;
        for(auto e : m)
            q.push({e.second, e.first});
        
        string ans;
        while(q.size() > 1) {
            auto curr = q.top(); q.pop();
            auto next = q.top(); q.pop();
            
            ans += curr.second;
            ans += next.second;
            
            if(--curr.first > 0) q.push(curr);
            if(--next.first > 0) q.push(next);
        }
        
        if(!q.empty()) {
            if(q.top().first > 1)
                return "";
            ans += q.top().second;
        }
        
        return ans;
    }
};