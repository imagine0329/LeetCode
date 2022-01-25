class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        int two_back = 1, one_back = 1;
        
        for(int i = 2; i <= s.length(); i++) {
            int current = 0;
            if(s[i - 1] != '0')
                current += one_back;
            int n = stoi(s.substr(i - 2, 2));
            if(n >= 10 && n <= 26)
                current += two_back;
            
            two_back = one_back;
            one_back = current;
        }
        
        return one_back;
    }
};