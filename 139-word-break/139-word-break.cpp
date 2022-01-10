class Solution {
private:
    vector<int> memo;
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        memo = vector<int>(s.length(), -1);
        return helper(s, dict, 0);
    }
    
    bool helper(string& s, unordered_set<string>& dict, int start)
    {
        if(start == s.length())
            return true;
        
        if(memo[start] != -1)
            return memo[start];
        
        for(int end=start+1; end<=s.length(); end++)
        {
            if(dict.find(s.substr(start, end-start)) != dict.end())
            {
                if(helper(s, dict, end))
                    return memo[start] = true;
            }
        }
        
        return memo[start] = false;
    }
};