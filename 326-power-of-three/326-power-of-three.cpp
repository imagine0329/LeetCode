class Solution {
public:
    bool isPowerOfThree(int n) {
        string converted = convertBase(n);
        
        if(converted.front() == '1') {
            string temp = converted.substr(1, converted.length()-1);
            if(temp.size() == 0 || stoll(temp) == 0)
                return true;
        }
        
        return false;
    }
    
    string convertBase(int n) {
        string str;
        
        while(n) {
            str = to_string(n % 3) + str;
            n /= 3;
        }
        
        return str;
    }
};