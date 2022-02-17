class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, int>> dist;
        for(int i = 0; i < points.size(); i++)
            dist.push_back({points[i][0] * points[i][0] + points[i][1] * points[i][1], i});
        
        sort(dist.begin(), dist.end());
        
        vector<vector<int>> ans;
        for(int i = 0; i < k; i++) {
            ans.push_back(points[dist[i].second]);
        }
        
        return ans;
    }
};