class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, int>> distance;
        for(int i = 0; i < points.size(); i++)
            distance.push_back({euclideanDistance(points[i]), i});
        
        quickSelect(distance, k - 1, 0, distance.size() - 1);
        
        vector<vector<int>> ans;
        for(int i = 0; i < k; i++)
            ans.push_back(points[distance[i].second]);
        
        return ans;
    }
    
    int partition(vector<pair<int, int>>& distance, int left, int right) {
        int pivot = left + (right - left) / 2;
        swap(distance[pivot], distance[right]);
        
        int j = left;
        while(j < right) {
            if(distance[j].first < distance[right].first)
                swap(distance[left++], distance[j]);
            j++;
        }
        
        swap(distance[left], distance[right]);
        return left;
    }
    
    void quickSelect(vector<pair<int, int>>& distance, int k, int left, int right) {
        if(left == right) return;
        int pivot = partition(distance, left, right);
        
        if(pivot == k)
            return;
        
        if(pivot > k)
            quickSelect(distance, k, left, pivot - 1);
        else
            quickSelect(distance, k, pivot + 1, right);
    }
    
    double euclideanDistance(vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    }
};