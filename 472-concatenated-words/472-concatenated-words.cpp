class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dict(words.begin(), words.end());
        vector<string> ans;

        for(auto word : words) {
            if(isConcatenate(dict, word))
                ans.push_back(word);
        }
        
        return ans;
    }
    
    bool isConcatenate(unordered_set<string>& dict, string word) {
        int n = word.length();
        if(n == 0) 
            return false;
        
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < i; j++) {
                if(i - j < n && dp[j] && dict.find(word.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};