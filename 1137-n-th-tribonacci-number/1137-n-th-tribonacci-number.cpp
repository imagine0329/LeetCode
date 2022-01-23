class Solution {
public:
    int tribonacci(int n) {
        vector<int> memo(n + 1, 0);
        return getTribonacci(n, memo);
    }
    
    int getTribonacci(int n, vector<int>& memo) {
        if(n < 3)
            return n == 0 ? 0 : 1;
        
        if(memo[n] != 0)
            return memo[n];
        
        memo[n] = getTribonacci(n-1, memo) + getTribonacci(n-2, memo) + getTribonacci(n-3, memo);
        return memo[n];
    }
};