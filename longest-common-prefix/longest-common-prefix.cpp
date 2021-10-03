class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        
        for(int i=0; i<strs[0].size(); i++)
        {
            int k = 1;
            for(; k<strs.size() && i<strs[k].size(); k++)
            {
                if(strs[k][i] != strs[0][i])
                    return ans;
            }
            
            if(k == strs.size())
                ans += strs[0][i];
        }
        
        return ans;
    }
};