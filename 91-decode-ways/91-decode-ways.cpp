class Solution {
public:
    int numDecodings(string s) {
        vector<int> memo(s.length(), -1);
        return recursive(s, memo, 0);
    }
    
    int recursive(string& s, vector<int>& memo, int index) {
        if(index == s.length()) return 1;
        if(memo[index] != -1) return memo[index];
        if(s[index] == '0') return 0;
        if(index == s.length() - 1) return 1;
        
        int ans = recursive(s, memo, index + 1);
        if(stoi(s.substr(index, 2)) <= 26)
            ans += recursive(s, memo, index + 2);
        
        return memo[index] = ans;
    }
};