class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> v;
        for(auto r : matrix) {
            for(auto c : r)
                v.push_back(c);
        }
        
        sort(v.begin(), v.end());
        return v[k - 1];
    }
};