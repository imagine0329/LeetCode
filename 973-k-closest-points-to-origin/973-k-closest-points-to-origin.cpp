class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> q;
        
        for(int i = 0; i < points.size(); i++) {
            int x = points[i][0], y = points[i][1];
            int area = (x * x) + (y * y);
            q.push({area, i});
            if(q.size() > k)
                q.pop();
        }
        
        vector<vector<int>> ans;
        for(int i = 0; i < k; i++) {
            ans.push_back(points[q.top().second]);
            q.pop();
        }
        
        return ans;
    }
};