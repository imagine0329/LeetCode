class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int longest = 0;
        
        int left = 0, right = 0;
        while(right < s.length())
        {
            char c = s[right];
            if(m.find(c) != m.end() && m[c] != -1)
            {
                left = m[c] + 1;
                for(auto n : m)
                {
                    if(n.second < left)
                        m[n.first] = -1;
                }
            }
            
            m[c] = right++;
            
            longest = max(longest, right - left);
        }
        
        return longest;
    }
};