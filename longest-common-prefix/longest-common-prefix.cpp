class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        return lcp(strs, 0, strs.size()-1);
    }
    
    string lcp(vector<string>& strs, int left, int right)
    {
        if(left == right)
            return strs[left];
        
        int mid = (left + right)/2;
        string str_l = lcp(strs, left, mid);
        string str_r = lcp(strs, mid+1, right);
        
        string ret;
        for(int i=0; i<min(str_l.length(), str_r.length()); i++)
        {
            if(str_l[i] != str_r[i])
                return ret;
            
            ret += str_l[i];
        }
        
        return ret;
    }
};