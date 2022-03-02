class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1;
        while(i >= 0 && isspace(s[i])) i--;
        
        int j = i;
        while(j >= 0 && !isspace(s[j])) j--;
        
        return i - j;
    }
};