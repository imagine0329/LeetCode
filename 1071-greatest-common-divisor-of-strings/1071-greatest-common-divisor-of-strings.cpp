class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1 + str2 != str2 + str1) return "";
        if(str1.length() < str2.length())
            return gcdOfStrings(str2, str1);
        if(str2.length() == 0)
            return str1;
        else
            return gcdOfStrings(str2, str1.substr(str2.length()));
    }
};