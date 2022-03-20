class Solution {
public:
    string longestPalindrome(string s) {
        int longest = 0;
        int start = 0;
        
        for(int i = 0; i < s.length(); i++) {
            int len1 = isPalindrome(s, i, i);
            int len2 = isPalindrome(s, i, i + 1);
            int len = max(len1, len2);
            if(longest < len) {
                longest = len;
                start = i - (len - 1) / 2;
            }
        }
        
        return s.substr(start, longest);
    }
    
    int isPalindrome(string s, int left, int right) {
        while(left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        
        return right - left - 1;
    }
};