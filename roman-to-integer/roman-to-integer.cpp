class Solution {
public:
    int getDecimal(char c)
    {
        switch(c)
        {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return -1;
        }
    }
    
    int romanToInt(string s) {
        int ans = 0;
        int prev = 0;
        
        for(int i = s.length()-1; i>=0; i--)
        {
            int curr = getDecimal(s[i]);
            
            if(curr == -1)
                return -1;
            
            if(prev > curr)
                ans -= curr;
            else
                ans += curr;
            
            prev = curr;
        }
        
        return ans;
    }
};