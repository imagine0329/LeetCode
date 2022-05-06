class Solution {
public:
    int racecar(int target) {
        vector<int> dp(target + 1, -1);
        
        for(int i = 1; i <= target; i++) {
            dp[i] = INT_MAX;
            int m = 1, j = 1;
            for(; j < i; j = (1 << ++m) -1) {
                for(int p = 0, q = 0; p < j; p = (1 << ++q) - 1)
                    dp[i] = min(dp[i], m + 1 + q + 1 + dp[i - (j - p)]);
            }

            dp[i] = min(dp[i], m + (i == j ? 0 : 1 + dp[j - i]));
        }
        
        return dp[target];
    }
};

/*

            s                       t
            0   1   2   3   4   5   6   7   8   9   10
instruction A   A       A               A       
speed       1   2       4               8
position    x   x       x               x

        A              R
    A       R       A       R
  A   R   A  R


position < t -> A
position > t -> R
         = t -> end
         
         */