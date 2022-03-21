class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> memo(s.length(), -1);
        return helper(dict, s, 0, memo);
    }
    
    bool helper(unordered_set<string>& dict, string s, int start, vector<int>& memo) {
        int n = s.length();
        if(start == n) return true;
        if(memo[start] != -1) return memo[start];
        for(int end = start; end < n; end++) {
            string str = s.substr(start, end - start + 1);
            if(dict.find(str) != dict.end()) {
                if(helper(dict, s, end + 1, memo)) return memo[start] = 1;
            }
        }
        return memo[start] = 0;
    }
};