class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int s_len = s.length();
        int t_len = t.length();
        
        if(s_len > t_len)
            return isOneEditDistance(t, s);
        
        if(t_len - s_len > 1)
            return false;
        
        for(int i=0; i<s_len; i++)
        {
            if(s[i] == t[i])
                continue;
            
            if(s_len == t_len)
                return s.substr(i+1) == t.substr(i+1);
            
            return s.substr(i) == t.substr(i+1);
        }
        
        return s_len + 1 == t_len;
    }
};