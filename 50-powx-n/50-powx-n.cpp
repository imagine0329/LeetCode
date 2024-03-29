class Solution {
public:
    double fastPow(double x, long long n)
    {
        if(n == 0)
            return 1.0;
        
        double half = fastPow(x, n/2);
        if(n % 2)
            return half * half * x;
        else
            return half * half;
    }
    
    double myPow(double x, int n)
    {
        long long N = n;
        if(N < 0)
        {
            x = 1/x;
            //N = -N;
        }
        
        return fastPow(x, N);
    }
};