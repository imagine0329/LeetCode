/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
    }
};*/

/*  Peak Valley Approach*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int valley = 0, peak = 0;
        int profit = 0;
        
        int i=0;
        while(i < prices.size()-1)
        {
            while(i < prices.size()-1 && prices[i] >= prices[i+1])
                i++;
            
            valley = i;
            
            while(i < prices.size()-1 && prices[i] < prices[i+1])
                i++;
            
            peak = i;
            
            profit += prices[peak] - prices[valley];
        }
        
        return profit;
    }
};


/*  Brute Force [TLE]
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return calculate(prices, 0);
    }
    
    int calculate(vector<int>& prices, int start)
    {
        if(start >= prices.size())
            return 0;
        
        int max = 0;
        for(int buy = start; buy<prices.size(); buy++)
        {
            int max_profit = 0;
            for(int sell = buy+1; sell<prices.size(); sell++)
            {
                if(prices[buy] < prices[sell])
                {
                    int profit = calculate(prices, sell+1) + (prices[sell] - prices[buy]);
                    if(profit > max_profit)
                        max_profit = profit;
                }
            }
            if(max_profit > max)
                max = max_profit;
        }
        
        return max;
    }
};*/