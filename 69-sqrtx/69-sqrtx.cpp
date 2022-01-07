class Solution {
public:
    int mySqrt(int x) {
        if(x < 2)
            return x;
        
        int n = exp(0.5*log(x)) + 1;
        return (long)n * n > x ? n-1 : n;
    }
    
};