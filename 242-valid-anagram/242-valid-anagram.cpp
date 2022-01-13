class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        
        unordered_map<char, int> m;
        
        for(auto c : s)
            m[c - 'a']++;
        
        for(auto c : t)
        {
            if(m[c - 'a']-- == 0)
                return false;
        }
        
        return true;
    }
};