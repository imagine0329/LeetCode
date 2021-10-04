class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        
        for(int i=0; i<strs[0].size(); i++)
        {
            int j = 1;
            for(; j<strs.size() && i<strs[j].size(); j++)
            {
                if(strs[j][i] != strs[0][i])
                    return ans;
            }
            
            if(j == strs.size())
                ans += strs[0][i];
        }
        
        return ans;
    }
};