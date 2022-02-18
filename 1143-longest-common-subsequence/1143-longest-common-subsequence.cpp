class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length(), n2 = text2.length();
        if(n1 > n2) return longestCommonSubsequence(text2, text1);
        
        vector<int> prev(n1 + 1, 0), curr(n1 + 1, 0);
        
        for(int c = n2 - 1; c >= 0; c--) {
            for(int r = n1 - 1; r >= 0; r--) {
                if(text1[r] == text2[c])
                    curr[r] = prev[r + 1] + 1;
                else
                    curr[r] = max(curr[r + 1], prev[r]);
            }
            
            prev = curr;
        }
        
        return prev[0];
    }
};