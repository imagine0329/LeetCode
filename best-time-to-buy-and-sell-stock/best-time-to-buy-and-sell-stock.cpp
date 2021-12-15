class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int profit = 0;
        
        for(auto p : prices)
        {
            if(p < minPrice)
                minPrice = p;
            else if(p - minPrice > profit)
                profit = p - minPrice;
        }
        
        return profit;
    }
};