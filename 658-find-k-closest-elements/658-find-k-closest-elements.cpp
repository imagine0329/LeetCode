class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int i = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int left = i - 1, right = i;
        
        while(right - left - 1 < k) {
            if(left == -1) {
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