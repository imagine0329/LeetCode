class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto compare = [&](const int& a, const int& b) {
            if(abs(a - x) == abs(b - x))
                return a < b;
            return abs(a - x) < abs(b - x);
        };
        
        sort(arr.begin(), arr.end(), compare);
        vector<int> ans(arr.begin(), arr.begin() + k);
        sort(ans.begin(), ans.end());
        return ans;
    }
};