class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - 1;
        
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(arr[mid] < x)
                left = mid + 1;
            else
                right = mid;
        }
        
        left--;
        while(right - left - 1 < k) {
            if(left < 0) {
                right++;
                continue;
            }
            
            if(right == arr.size() || abs(arr[left] - x) <= abs(arr[right] - x))
                left--;
            else
                right++;
        }
        
        return vector<int>(arr.begin() + left + 1, arr.begin() + right);
    }
};