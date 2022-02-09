class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        int hottest = 0;
        
        for(int i = n - 1; i >= 0; i--) {
            if(temperatures[i] < hottest) {
                int days = 1;
                while(temperatures[i] >= temperatures[i + days])
                    days += ans[i + days];
                ans[i] = days;
            }
            else
                hottest = temperatures[i];
        }
        
        
        return ans;
    }
};