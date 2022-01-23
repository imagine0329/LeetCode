class Solution {
public:
    int tribonacci(int n) {
        if(n < 3)
            return n == 0 ? 0 : 1;
        
        int first = 0, second = 1, third = 1;
        int res;
        for(int i = 3; i <= n; i++) {
            res = first + second + third;
            first = second;
            second = third;
            third = res;
        }
        
        return res;
    }
};