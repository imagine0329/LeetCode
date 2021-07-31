class Solution {
public:
    int romanToInt(string s) {
        char ch = 0;
        char prev = 0;
        int decimal = 0;
        
        prev = s.back();
        while(!s.empty())
        {
            ch = s.back();
            s.pop_back();
            decimal += getAddition(ch, prev);
            prev = ch;
        }
        
        return decimal;
    }
    
    int getAddition(char ch, char prev)
    {
        switch(ch)
        {
            case 'I':
                if(prev == ch)
                    return 1;
                else
                    return -1;
                
            case 'V':
                return 5;
                
            case 'X':
                if(prev == ch || prev == 'I' || prev == 'V')
                    return 10;
                else
                    return -10;
                
            case 'L':
                return 50;
                
            case 'C':
                if(prev == ch || prev == 'I' || prev == 'V'
                    || prev == 'X' || prev == 'L')
                    return 100;
                else
                    return -100;
                
            case 'D':
                return 500;
                
            case 'M':
                return 1000;
                
            default:
                return 0;
        }
    }
};