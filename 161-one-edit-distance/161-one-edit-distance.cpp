class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int n = s.length(), m = t.length();
        if(n > m)
            return isOneEditDistance(t, s);
        
        if(s == t || m - n > 1)
            return false;
        
        int ps = 0, pt = 0;
        
        for(int i=0; i<n; i++)
        {
            if(s[i] == t[i])
                continue;
            
            if(n == m)
                return s.substr(i+1) == t.substr(i+1);
            
            return s.substr(i) == t.substr(i+1);
        }
        
        return n+1 == m;
    }
};