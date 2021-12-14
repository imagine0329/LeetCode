class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.length();
        if(n < 1)
            return 0;
        if(haystack.length() < 1)
            return -1;
        
        int start = 0;
        while(start + n <= haystack.length())
        {
            string str = haystack.substr(start, n);
            if(str == needle)
                return start;
            
            start++;
        }
        
        return -1;
    }
};