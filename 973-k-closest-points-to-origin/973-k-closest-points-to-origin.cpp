class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        return quickSelect(points, k);
    }
    
private:
    vector<vector<int>> quickSelect(vector<vector<int>>& points, int k) {
        int left = 0, right = points.size() - 1;
        int pivot = points.size();
        while(pivot != k) {
            pivot = partition(points, left, right);
            if(pivot < k)
                left = pivot;
            else
                right = pivot - 1;
        }
        
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
    
    int partition(vector<vector<int>>& points, int left, int right) {
        vector<int>& pivot = choosePivot(points, left, right);
        int pivotDist = squareDistance(pivot);
        while(left < right) {
            if(squareDistance(points[left]) >= pivotDist) {
                swap(points[left], points[right]);
                right--;
            }
            else
                left++;
        }
        
        if(squareDistance(points[left]) < pivotDist)
            left++;
        
        return left;
    }
    
    vector<int>& choosePivot(vector<vector<int>>& points, int left, int right) {
        return points[left + (right - left) / 2];
    }
    
    int squareDistance(vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    }
};