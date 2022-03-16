class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        int longest = 0;
        unordered_map<char, int> m;
        while(right < s.length()) {
            if(m.find(s[right]) != m.end()) {
                if(m[s[right]] < left)
                    m.erase(s[right]);
                else
                    left = m[s[right]] + 1;
            }
                
            
            longest = max(longest, right - left + 1);
            m[s[right]] = right;
            right++;
        }
        return longest;
    }
};