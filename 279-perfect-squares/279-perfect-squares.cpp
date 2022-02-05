class Solution {
public:
    int numSquares(int n) {
        int bound = sqrt(n);
        vector<int> memo(n + 1, INT_MAX);
        return recur(n, bound, memo);
    }
    
    int recur(int n, int start, vector<int>& memo) {
        if(n < 0) return INT_MAX;
        if(memo[n] != INT_MAX) return memo[n];
        if(n == 0)
            return 0;
        
        int minimum = INT_MAX;
        for(int i = start; i >= 1; i--)
            minimum = min(minimum, recur(n - (i * i), start, memo));
        
        if(minimum != INT_MAX)
            memo[n] = minimum + 1;
        
        return memo[n];
    }
};