class Solution {
public:
    int reverseInteger(int x)
    {
        int reversed = 0;
        
        while(x != 0)
        {
            int pop = x % 10;
            x /= 10;
            
            if(reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && reversed % 10 > 7))
                return -1;
            if(reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && reversed % 10 < -8))
                return -1;
            
            reversed = (reversed * 10) + pop;
        }
        
        return reversed;
    }
    
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        
        if(x == reverseInteger(x))
            return true;
        else
            return false;
    }
};