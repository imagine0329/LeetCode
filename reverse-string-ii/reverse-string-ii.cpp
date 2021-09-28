class Solution {
public:
    string reverseStr(string s, int k) {
        for(int start = 0; start < s.size(); start += k*2)
        {
            for(int i = start, j = min((start + k) - 1, (int)s.size() - 1); i < j; i++, j--)
                swap(s[i], s[j]);
        }
        
        return s;
    }
};