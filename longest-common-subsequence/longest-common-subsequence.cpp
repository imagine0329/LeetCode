class Solution {
private:
    vector<vector<int>> memo;
    string t1, t2;
    
public:
    int longestCommonSubsequence(string text1, string text2) {
        memo = vector<vector<int>>(text1.size()+1, vector<int>(text2.size()+1, -1));
        for(int i=0; i<memo.size(); i++)
            memo[i][memo[0].size()-1] = 0;
        for(int i=0; i<memo[0].size(); i++)
            memo[memo.size()-1][i] = 0;
        
        t1 = text1;
        t2 = text2;
        
        return lcs(0, 0);
    }
    
    int lcs(int m, int n)
    {
        if(memo[m][n] != -1)
            return memo[m][n];
        
        if(t1[m] == t2[n])
            memo[m][n] = 1 + lcs(m+1, n+1);
        else
            memo[m][n] = max(lcs(m, n+1), lcs(m+1, n));
        
        return memo[m][n];
    }
};