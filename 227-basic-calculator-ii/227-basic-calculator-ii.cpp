class Solution {
public:
    int calculate(string s) {
        int curr = 0, prev = 0, res = 0;
        char op = '+';
        stack<int> st;
        
        for(int i=0; i<s.length(); i++) {
            char c = s[i];
            if(isdigit(c))
               curr = (curr * 10) + (c - '0');
            
            if(!isdigit(c) && !iswspace(c) || i == s.length() - 1) {
                if(op == '+' || op == '-') {
                    res += prev;
                    prev = op == '+' ? curr : -curr;
                }
                else if(op == '*')
                    prev = prev * curr;
                else
                    prev = prev / curr;
                
                op = c;
                curr = 0;
            }
        }
        
        res += prev;
        
        return res;
    }
};