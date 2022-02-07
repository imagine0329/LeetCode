class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        
        int i = 0;
        while(i < s.length()) {
            string str;
            while(i < s.length() && !isspace(s[i]))
                str += s[i++];
            
            if(str.size() > 0)
                st.push(str);
            
            while(i < s.length() && isspace(s[i]))
                i++;
        }
        
        string ans;
        while(!st.empty()) {
            ans += st.top() + " ";
            st.pop();
        }
        
        ans.pop_back();
        return ans;
    }
};