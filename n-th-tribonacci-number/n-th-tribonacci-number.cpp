class Solution {
private:
    vector<int> memo;
    
public:
    int tribonacci(int n) {
        memo.assign(n+1, -1);
        
        return dp(n);
    }
    
    int dp(int i)
    {
        if(i == 0)
            return 0;
        
        if(i < 3)
            return 1;
        
        if(memo[i] == -1)
            memo[i] = dp(i-3) + dp(i-2) + dp(i-1);
        
        return memo[i];
    }
};