class Solution {
private:
    vector<int> memo;

public:
    int climbStairs(int n) {
        if(n <= 1)
            return 1;
        
        memo = vector<int>(n+1, 0);
        memo[0] = 1;
        memo[1] = 1;
        
        return climb(n);
    }
    
    int climb(int n)
    {
        if(memo[n])
            return memo[n];
        
        return memo[n] = climb(n-1) + climb(n-2);
    }
};