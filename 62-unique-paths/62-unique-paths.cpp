class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans = 1;
        
        for(int i=m+n-2, j=1; i>max(m, n)-1; i--, j++)
            ans = (ans * i) / j;
        
        return (int)ans;
    }
    
};