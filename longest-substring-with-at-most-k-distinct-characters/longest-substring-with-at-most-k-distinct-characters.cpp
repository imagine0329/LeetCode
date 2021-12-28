
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(s.length() * k == 0)
            return 0;
        
        unordered_map<char, int> m;
        
        int left = 0, right = 0;
        int longest = 1;
        while(right < s.length())
        {
            int c = s[right];
            m[c] = right++;
            
            if(m.size() > k)
            {
                int leftmost = INT_MAX;
                int ch;
                for(auto n : m)
                {
                    if(leftmost > n.second)
                    {
                        leftmost = n.second;
                        ch = n.first;
                    }
                }
                m.erase(ch);
                left = leftmost + 1;
            }
            
            longest = max(longest, right - left);
        }
        
        return longest;
    }
};