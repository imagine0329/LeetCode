class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> p;
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));
        
        dfs(s, dp, 0, ans, p);
        return ans;
    }
    
    void dfs(string s, vector<vector<bool>>& dp, int start, vector<vector<string>>& ans, vector<string>& p) {
        if(start == s.length()) {
            ans.push_back(p);
            return;
        }
        
        for(int end = start; end < s.length(); end++) {
            if(s[start] == s[end] && (end - start <= 2 || dp[start + 1][end - 1])) {
                dp[start][end] = true;
                p.push_back(s.substr(start, end - start + 1));
                dfs(s, dp, end + 1, ans, p);
                p.pop_back();
            }
        }
    }
};