class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<double> distance;
        vector<int> remain;
        double low = 0, high = 0;
        
        for(int i = 0; i < points.size(); i++) {
            distance.push_back(euclideanDistance(points[i]));
            remain.push_back(i);
            high = max(high, distance[i]);
        }
        
        vector<int> closest;
        while(k) {
            double mid = low + (high - low) / 2;
            vector<vector<int>> res = splitDistance(remain, distance, mid);
            if(res[0].size() > k) {
                remain.swap(res[0]);
                high = mid;
            }
            else {
                k -= res[0].size();
                closest.insert(closest.end(), res[0].begin(), res[0].end());
                remain.swap(res[1]);
                low = mid;
            }
        }
        
        vector<vector<int>> ans;
        for(auto i : closest)
            ans.push_back(points[i]);
        
        return ans;
    }
    
    vector<vector<int>> splitDistance(vector<int>& remain, vector<double>& distance, double mid) {
        vector<vector<int>> res(2);
        for(auto i : remain) {
            if(distance[i] <= mid)
                res[0].push_back(i);
            else
                res[1].push_back(i);
        }
        
        return res;
    }
    
    double euclideanDistance(vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    }
};