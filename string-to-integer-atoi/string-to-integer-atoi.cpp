class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        
        int i = 0;
        while(i < s.length() && s[i] == ' ')
            i++;
        
        if(s[i] == '+' || s[i] == '-')
        {
            if(s[i++] == '-')
                sign = -1;
            
            if(s[i] == '-')
                return 0;
        }
        
        int base = 0;
        for(; i<s.length() && isdigit(s[i]); i++)
        {
            if(base > INT_MAX/10 || (base == INT_MAX/10 && s[i]-'0' > INT_MAX%10))
            {
                if(sign == 1)   return INT_MAX;
                else return INT_MIN;
            }
            
            base = (base*10) + (s[i] - '0');
        }
        
        return base*sign;
    }
    
    
};