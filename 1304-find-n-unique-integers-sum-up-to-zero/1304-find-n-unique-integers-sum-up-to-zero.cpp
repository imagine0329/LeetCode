class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n);
        int k = n / 2;
        
        for(int i = 0; i < n / 2; i++) {
            ans[i] = k;
            ans[n - i - 1] = k * -1;
            k--;
        }
        
        return ans;
    }
};