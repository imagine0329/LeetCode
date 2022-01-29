class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n);
        
        for(int i = 1; i < n; i++) {
            ans[i] = i;
            ans[0] -= i;
        }
        return ans;
    }
};