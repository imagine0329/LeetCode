class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        
        for(int len = 1; len <= s.length(); len++) {
            for(int i = 0; i < len; i++) {
                string str = s.substr(i, len - i);
                if(dp[i] && dict.find(str) != dict.end()) {
                    dp[len] = true;
                    break;
                }
            }
        }
        
        return dp[s.length()];
    }
};