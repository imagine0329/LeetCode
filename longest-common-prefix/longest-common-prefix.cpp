class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() < 1)
            return "";
        
        string prefix = strs[0];
        for(int i=1; i<strs.size(); i++)
        {
            while(strs[i].find(prefix) != 0)
                prefix.pop_back();
            
            if(prefix.size() == 0)
                return "";
        }
        
        return prefix;
    }
};