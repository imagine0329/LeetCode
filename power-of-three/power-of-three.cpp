class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n < 1)
            return false;
        
        string str = convertBase(3, n);
        if(str.front() == '1')
        {
            string temp = str.substr(1, str.length()-1);
            if(temp.size() == 0 || stoll(temp) == 0)
                return true;
        }
        
        return false;
    }
    
    string convertBase(int base, int n)
    {
        string str;
        
        while(n > 0)
        {
            int remainder = n % base;
            str = to_string(remainder) + str;
            
            n /= 3;
        }
        
        return str;
    }
};