class Solution {
public:
    int reverse(int x) {
        bool sign = x < 0 ? false : true;
        int ans = 0;
        
        while(x != 0) {
            int y = x % 10;
            x /= 10;
            
            if(sign == false && (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && y < -8)))
                return 0;
            if(sign && (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && y > 7)))
                return 0;
            
            ans = (ans * 10) + y;
        }
        return ans;
    }
};