class Solution {
public:
    int numSquares(int n) {
        int temp = n;
        while(temp % 4 == 0)
            temp /= 4;
        if(temp % 8 == 7)
            return 4;
        
        if(isSquare(n))
            return 1;
        
        for(int i = 1; i < sqrt(n); i++) {
            if(isSquare(n - (i * i)))
                return 2;
        }
        
        return 3;
    }
    
    bool isSquare(int n) {
        int sq = (int) sqrt(n);
        return n == sq * sq;
    }
};