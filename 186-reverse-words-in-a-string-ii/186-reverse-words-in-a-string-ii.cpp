class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        
        int i = 0, j = 0;
        while(i < s.size()) {
            while(j < s.size() && isalpha(s[j])) j++;
            reverse(s.begin() + i, s.begin() + j);
            i = ++j;
        }
    }
};