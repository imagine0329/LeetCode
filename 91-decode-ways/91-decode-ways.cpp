class Solution {
public:
    int numDecodings(string s) {
        unordered_map<int, int> memo;
        return recursive(s, 0, memo);
    }
    
    int recursive(string s, int i, unordered_map<int, int>& memo) {
        if(memo.find(i) != memo.end())
            return memo[i];
        if(i == s.length())
            return 1;
        if(s[i] == '0')
            return 0;
        if(i == s.length() - 1)
            return 1;
        
        memo[i] = recursive(s, i + 1, memo);
        if(stoi(s.substr(i, 2)) <= 26)
            memo[i] += recursive(s, i + 2, memo);
        
        return memo[i];
    }
};