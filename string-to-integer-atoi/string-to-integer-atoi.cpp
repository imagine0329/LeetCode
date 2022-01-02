class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        int i = s.find_first_not_of(' ');
        if(i == -1)
            return 0;
        
        if(s[i] == '-' || s[i] == '+')
            sign = s[i++] == '+' ? 1 : -1;
        
        int ans = 0;
        while(isdigit(s[i]))
        {
            if(ans > INT_MAX/10 || (ans == INT_MAX/10 && s[i] - '0' > 7))
                return sign == 1 ? INT_MAX : INT_MIN;
                
            ans = (ans * 10) + (s[i++] - '0');
        }
        
        return ans * sign;
    }
};