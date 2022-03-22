class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount + 1);
        return backtracking(coins, amount, memo);
    }
    
    int backtracking(vector<int>& coins, int remain, vector<int>& memo) {
        if(remain < 0) return -1;
        if(remain == 0) return 0;
        if(memo[remain] != 0) return memo[remain];
        
        int min = INT_MAX;
        for(auto coin : coins) {
            int res = backtracking(coins, remain - coin, memo);
            if(res >= 0 && min > res)
                min = res + 1;
        }
        
        memo[remain] = min == INT_MAX ? -1 : min;
        return memo[remain];
    }
};