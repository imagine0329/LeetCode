class Solution {
public:
    int numDecodings(string s) {
        int two_back = 1;
        int one_back = s[0] == '0' ? 0 : 1;
        
        for(int i = 1; i < s.length(); i++) {
            int curr = 0;
            if(s[i] != '0')
                curr = one_back;
            
            int two = stoi(s.substr(i - 1, 2));
            if(two >= 10 && two <= 26)
                curr += two_back;
            
            two_back = one_back;
            one_back = curr;
        }
        
        return one_back;
    }
};