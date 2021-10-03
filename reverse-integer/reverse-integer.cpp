class Solution {
public:
    //  INT_MAX = 2147483647
    //  INT_MIN = -2147483648
    int reverse(int x) {
        int reversed = 0;
        
        while(x != 0)
        {
            int pop = x % 10;
            x /= 10;
            
            // overflow check
            if(reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && reversed % 10 > 7))
                return 0;
            if(reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && reversed % 10 < -8))
                return 0;
            
            reversed = (reversed * 10) + pop;
        }
        
        return reversed;
    }
};