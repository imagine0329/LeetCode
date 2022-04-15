class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> q;
        
        for(int i = 0; i < points.size(); i++) {
            q.push({points[i][0] * points[i][0] + points[i][1] * points[i][1], i});
            if(q.size() > k)
                q.pop();
        }
        
        vector<vector<int>> ans;
        while(!q.empty()) {
            int i = q.top().second;
            q.pop();
            ans.push_back(points[i]);
        }
        
        return ans;
    }
};