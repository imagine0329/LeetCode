class Solution {
public:
    int fib(int n) {
        vector<int> memo(n + 1, -1);
        return fibonacci(n, memo);
    }
    
    int fibonacci(int n, vector<int>& memo) {
        if(n <= 1) return n;
        if(memo[n] != -1) return memo[n];
        return memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
    }
};