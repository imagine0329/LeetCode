class Solution {
public:
    int racecar(int target) {
        vector<int> dp(target + 1, -1);
        return racecar(target, dp);
    }
    
    int racecar(int i, vector<int>& dp) {
        if(dp[i] >= 0)
            return dp[i];
        
        dp[i] = INT_MAX;
        int m = 1, j = 1;
        for(; j < i; j = (1 << ++m) -1) {
            for(int p = 0, q = 0; p < j; p = (1 << ++q) - 1)
                dp[i] = min(dp[i], m + 1 + q + 1 + racecar(i - (j - p), dp));
        }
        
        dp[i] = min(dp[i], m + (i == j ? 0 : 1 + racecar(j - i, dp)));
        return dp[i];
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