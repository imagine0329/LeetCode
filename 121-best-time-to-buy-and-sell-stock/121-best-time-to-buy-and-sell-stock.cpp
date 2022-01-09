class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        
        int profit = 0;
        int min = INT_MAX;
        for(auto n : prices)
        {
            if(n > min)
                profit = max(profit, n - min);
            else
                min = n;
        }
        
        return profit;
    }
};