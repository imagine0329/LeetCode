class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int longest = 0;
        
        int left = 0;
        for(int right=0; right<s.length(); right++)
        {
            char c = s[right];
            if(m.find(c) != m.end() && left <= m[c])
                left = m[c] + 1;
            
            m[c] = right;
            
            longest = max(longest, right - left + 1);
        }
        
        return longest;
    }
};