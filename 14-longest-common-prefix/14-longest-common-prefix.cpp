class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        
        for(int i=0; i<strs[0].size(); i++) {
            char c = strs[0][i];
            for(auto s : strs) {
                if(i == s.size() || s[i] != c)
                    return ans;
            }
            ans += c;
        }
        
        return ans;
    }
};


/*

     i
leets
leetcode
leetabcds

ans = leet

*/