class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int> s;
        int ans = 0;
        
        for(int i = 0; i <= n; i++) {
            while(!s.empty() && arr[s.top()] > (i == n ? -1 : arr[i])) {
                int j = s.top(); s.pop();
                int k = s.empty() ? -1 : s.top();
                ans = (ans + (long long)arr[j] * (i - j) * (j - k)) % 1000000007;
            }
            s.push(i);
        }
        return ans;
    }
};