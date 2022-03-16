class Solution {
public:
    int myAtoi(string s) {
        int i = s.find_first_not_of(' ');
        if(i == -1) return 0;
        
        int sign = 1;
        if(s[i] == '-' || s[i] == '+')
            sign = s[i++] == '+' ? 1 : -1;
        
        int x = 0;
        while(i < s.length() && isdigit(s[i])) {
            if(x > INT_MAX / 10 || (x == INT_MAX / 10 && s[i] - '0' > 7))
                return sign == -1 ? INT_MIN : INT_MAX;
            x = (x * 10) + (s[i++] - '0');
        }
        return x * sign;
    }
};