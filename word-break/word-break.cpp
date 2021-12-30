class Solution {
private:
    vector<int> memo;
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        memo = vector<int>(s.length(), -1);
        return segment(s, dict, 0);
    }
    
    bool segment(string s, unordered_set<string>& dict, int i)
    {
        if(i == s.length())
            return true;
        
        if(memo[i] != -1)
            return memo[i];
        
        for(int j=i; j<s.length(); j++)
        {
            if(dict.find(s.substr(i, j-i+1)) != dict.end())
            {
                if(segment(s, dict, j+1))
                    return memo[i] = true;
            }
        }
        
        return memo[i] = false;
    }
};