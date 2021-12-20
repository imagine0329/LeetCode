class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> p(n, vector<bool>(n, false));
        int max_len = 1, start = 0;
        
        for(int i=0; i<n; i++)
        {
            p[i][i] = true;
            if(i < n-1 && s[i] == s[i+1])
            {
                p[i][i+1] = true;
                start = i;
                max_len = 2;
            }    
        }
        
        
        for(int k=3; k<=n; k++)
        {
            for(int i=0; i<n-k+1; i++)
            {
                int j = i+k-1;
                if(s[i] == s[j] && p[i+1][j-1])
                {
                    p[i][j] = true;
                    if(max_len < k)
                    {
                        start = i;
                        max_len = k;
                    }
                }
            }
        }
        
        return s.substr(start, max_len);
    }
};