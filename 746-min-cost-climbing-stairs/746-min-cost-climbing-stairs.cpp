class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> memo(n + 1, -1);
        return minCost(cost, memo, n);
    }
    
    int minCost(vector<int>& cost, vector<int>& memo, int i) {
        if(i <= 1) return 0;
        if(memo[i] != -1) return memo[i];
        
        int one = cost[i - 1] + minCost(cost, memo, i - 1);
        int two = cost[i - 2] + minCost(cost, memo, i - 2);
        
        return memo[i] = min(one, two);
    }
};