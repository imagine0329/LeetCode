class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> memo(n + 1, vector<int>(target + 1, -1));
        return helper(n, k, target, memo);
    }
    
    int helper(int n, int k, int remain, vector<vector<int>>& memo) {
        if(n == 0 || remain <= 0) return n == 0 && remain == 0;
        if(memo[n][remain] != -1) return memo[n][remain];
        int res = 0;
        for(int i = 1; i <= k; i++)
            res = (res + helper(n - 1, k, remain - i, memo)) % 1000000007;
        return memo[n][remain] = res;
    }
};