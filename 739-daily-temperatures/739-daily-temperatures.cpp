class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<pair<int, int>> s;
        
        for(int i = 0; i < n; i++) {
            while(!s.empty() && s.top().first < temperatures[i]) {
                int j = s.top().second; s.pop();
                ans[j] = i - j;
            }

            s.push({temperatures[i], i});
        }
        
        while(!s.empty()) {
            int i = s.top().second; s.pop();
            ans[i] = 0;
        }
        
        return ans;
    }
};