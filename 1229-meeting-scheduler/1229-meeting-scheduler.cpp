class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        for(auto s : slots1)
            if(s[1] - s[0] >= duration) q.push(s);
        
        for(auto s : slots2)
            if(s[1] - s[0] >= duration) q.push(s);
        
        while(q.size() > 1) {
            auto s1 = q.top();
            q.pop();
            auto s2 = q.top();
            if(s1[1] >= s2[0] + duration)
                return {s2[0], s2[0] + duration};
        }
        
        return {};
    }
};