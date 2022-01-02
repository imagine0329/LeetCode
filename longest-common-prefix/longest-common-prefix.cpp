class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret;
        
        for(int i=0; i<strs[0].size(); i++)
        {
            char c = strs[0][i];
            for(auto s : strs)
            {
                
                if(i == s.size())
                    return ret;
                
                if(s[i] != c)
                    return ret;
            }
            
            ret += c;
        }
        
        return ret;
    }
    
};