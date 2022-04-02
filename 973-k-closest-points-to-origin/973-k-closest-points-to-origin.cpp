class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> q;
        
        for(auto p : points) {
            q.push({p[0] * p[0] + p[1] * p[1], p});
            if(q.size() > k)
                q.pop();
        }
        
        vector<vector<int>> ans;
        while(!q.empty()) {
            ans.push_back(q.top().second);
            q.pop();
        }
        
        return ans;
    }
};