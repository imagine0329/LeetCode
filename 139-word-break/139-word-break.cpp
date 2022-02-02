class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> memo(s.length(), -1);
        return helper(s, dict, memo, 0) == 1 ? true : false;
    }
    
    bool helper(string& s, unordered_set<string>& dict, vector<int>& memo, int start) {
        if(start == s.length()) return 1;
        if(memo[start] != -1) return memo[start];
        
        for(int i = start; i < s.length(); i++) {
            string str = s.substr(start, i - start + 1);
            if(dict.find(str) != dict.end()) {
                if(helper(s, dict, memo, i + 1))
                    return memo[start] = 1;
            }
        }
        
        return memo[start] = 0;
    }
};