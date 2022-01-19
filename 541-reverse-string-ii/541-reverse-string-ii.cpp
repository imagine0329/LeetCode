class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length();
        for(int i = 0; i < n; i+=2*k) {
            for(int l = i, j = min(i+k-1, n-1); l < j; l++, j--)
                swap(s[l], s[j]);
        }
        
        return s;
    }
};