class Solution {
public:
    int climbStairs(int n) {
        vector<int> memo(n+1, 0);
        return climb(memo, n);
    }
    
    int climb(vector<int>& memo, int n)
    {
        if(n == 0)
        {
            memo[n] = 1;
            return 1;
        }    
        
        if(n < 0)
            return 0;
        
        if(memo[n] > 0)
            return memo[n];
        
        memo[n] = climb(memo, n-1) + climb(memo, n-2);
        return memo[n];
    }
};