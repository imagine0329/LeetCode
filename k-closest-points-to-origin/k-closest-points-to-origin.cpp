class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> q;
        
        for(int i=0; i<points.size(); i++)
            q.push({getDistance(points[i]), i});
        
        vector<vector<int>> ans;
        for(int i=0; i<k; i++)
        {
            ans.push_back(points[q.top().second]);
            q.pop();
        }
        
        return ans;
    }
    
    double getDistance(vector<int> point)
    {
        return sqrt(pow(point.front(), 2) + pow(point.back(), 2));
    }
};