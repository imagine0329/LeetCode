class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> leftMin(n), rightMax(n);
        
        leftMin[0] = prices[0];
        rightMax[n - 1] = prices[n - 1];
        for(int i = 1; i < n; i++)
            leftMin[i] = min(prices[i], leftMin[i - 1]);
        for(int i = n - 2; i >= 0; i--)
            rightMax[i] = max(prices[i], rightMax[i + 1]);
        
        int profit = 0;
        for(int i = 0; i < n; i++)
            profit = max(profit, rightMax[i] - leftMin[i]);
        
        return profit;
    }
};