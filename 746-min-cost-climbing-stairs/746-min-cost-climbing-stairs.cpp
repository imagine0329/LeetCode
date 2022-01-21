class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> memo(cost.size() + 1, 0);
        return climb(cost, memo, 0);
    }
    
    int climb(vector<int>& cost, vector<int>& memo, int i) {
        if(i > cost.size())
            return 0;
        
        if(memo[i] != 0)
            return memo[i];
        
        int val = i == 0 ? 0 : cost[i-1];
        memo[i] = min(climb(cost, memo, i+1), climb(cost, memo, i+2)) + val;
        return memo[i];
    }
};