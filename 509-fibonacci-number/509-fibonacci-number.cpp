class Solution {
public:
    int fib(int n) {
        vector<int> memo(n + 1, -1);
        return fibonacci(n, memo);
    }
    
    int fibonacci(int n, vector<int>& memo) {
        if(n == 0) return 0;
        if(n < 3) return 1;
        if(memo[n] != -1) return memo[n];
        return memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
    }
};