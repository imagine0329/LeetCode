class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        
        int n = prices.size();
        vector<int> left_min(n), right_max(n);
        left_min[0] = prices[0];
        right_max[n-1] = prices[n-1];
        
        for(int i=1; i<n; i++)
        {
            left_min[i] = min(left_min[i-1], prices[i]);
            right_max[n-i-1] = max(right_max[n-i], prices[n-i-1]);
        }
        
        int profit = 0;
        for(int i=0; i<n; i++)
            profit = max(profit, right_max[i] - left_min[i]);
        
        return profit;
    }
};