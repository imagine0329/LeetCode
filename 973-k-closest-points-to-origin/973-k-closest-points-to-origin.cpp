class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, int>> distance;
        for(int i = 0; i < points.size(); i++)
            distance.push_back({points[i][0] * points[i][0] + points[i][1] * points[i][1], i});
        
        quickSelect(distance, k - 1, 0, points.size() - 1);
        
        vector<vector<int>> ans;
        for(int i = 0; i < k; i++)
            ans.push_back(points[distance[i].second]);
        
        return ans;
    }
    
    void quickSelect(vector<pair<int, int>>& distance, int k, int left, int right) {
        if(left == right) return;
        
        int pivot = (left + right) / 2;
        pivot = partition(distance, left, right, pivot);
        
        if(pivot == k) return;
        if(pivot > k) quickSelect(distance, k, left, pivot - 1);
        else quickSelect(distance, k, pivot + 1, right);
    }
    
    int partition(vector<pair<int, int>>& distance, int left, int right, int pivot) {
        swap(distance[right], distance[pivot]);
        
        int i = left;
        while(i < right) {
            if(distance[i].first < distance[right].first)
                swap(distance[left++], distance[i]);
            i++;
        }
        swap(distance[left], distance[right]);
        return left;
    }
};