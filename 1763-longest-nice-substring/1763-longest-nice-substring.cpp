class Solution {
public:
    string longestNiceSubstring(string s) {
        if(s.length() < 2) return "";
        unordered_set<char> letters(s.begin(), s.end());
        for(int i = 0; i < s.length(); i++) {
            if(letters.find(tolower(s[i])) == letters.end() || letters.find(toupper(s[i])) == letters.end()) {
                string s1 = longestNiceSubstring(s.substr(0, i));
                string s2 = longestNiceSubstring(s.substr(i + 1));
                return s1.length() >= s2.length() ? s1 : s2;
            }
        }
        
        return s;
    }
};