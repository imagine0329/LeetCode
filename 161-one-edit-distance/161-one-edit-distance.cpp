class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int n = s.length(), m = t.length();
        if(n > m)
            return isOneEditDistance(t, s);
        
        if(s == t || m - n > 1)
            return false;
        
        int ps = 0, pt = 0;
        bool foundDiff = false;
        
        while(ps < n && pt < m)
        {
            if(s[ps] != t[pt])
            {
                if(foundDiff)
                    return false;
                foundDiff = true;
                
                if(n == m)
                    ps++;
                
                pt++;
            }    
            else
            {
                ps++;
                pt++;
            }
        }
        
        return true;
    }
};