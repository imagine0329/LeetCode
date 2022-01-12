class Solution {
public:
    int calculate(string s) {
        int curr = 0;
        char op = '+';
        stack<int> st;
        
        for(int i=0; i<s.length(); i++) {
            char c = s[i];
            if(isdigit(c))
               curr = (curr * 10) + (c - '0');
            
            if(!isdigit(c) && !iswspace(c) || i == s.length() - 1) {
                if(op == '+')       
                    st.push(curr);
                else if(op == '-')  
                    st.push(-curr);
                else {
                    int prev = st.top();
                    st.pop();
                    if(op == '*')
                        st.push(prev * curr);
                    else
                        st.push(prev / curr);
                }
                
                op = c;
                curr = 0;
            }
        }
        
        int res = 0;
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        
        return res;
    }
};