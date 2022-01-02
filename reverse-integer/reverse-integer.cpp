class Solution {
public:
    //  INT_MAX = 2147483647
    //  INT_MIN = -2147483648
    int reverse(int x) {
        int ans = 0;
        while(x != 0)
        {
            int r = x % 10;
            x /= 10;
            
            if(ans > INT_MAX/10 || (ans == INT_MAX/10 && r > 7))
                return 0;
            if(ans < INT_MIN/10 || (ans == INT_MIN/10 && r < -8))
                return 0;
            
            ans = (ans * 10) + r;
        }
        
        return ans;
    }
};