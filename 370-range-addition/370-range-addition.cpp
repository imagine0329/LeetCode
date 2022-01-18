class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> ans(length, 0);
        
        for(auto u : updates) {
            ans[u[0]] += u[2];
            if(u[1] < length - 1)
                ans[u[1] + 1] -= u[2];
        }
        
        partial_sum(ans.begin(), ans.end(), ans.begin());
        
        return ans;
    }
};