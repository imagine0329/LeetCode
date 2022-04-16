class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> memo(s.length(), -1);
        
        return recur(s, dict, 0, memo);
    }
    
    bool recur(string s, unordered_set<string>& dict, int start, vector<int>& memo) {
        if(start == s.length())
            return true;
        
        if(memo[start] != -1)
            return memo[start];
        
        for(int end = start; end < s.length(); end++) {
            string str = s.substr(start, end - start + 1);
            if(dict.find(str) != dict.end()) {
                if(recur(s, dict, end + 1, memo))
                    return memo[start] = true;
            }
        }
        return memo[start] = false;
    }
};