class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> m;
        
        int left = 0, right = 0;
        int longest = 1;
        
        while(right < s.length())
        {
            char c = s[right];
            m[c] = right++;
            
            if(m.size() > 2)
            {
                int leftmost = INT_MAX;
                for(auto n : m)
                    leftmost = min(leftmost, n.second);
                
                left = leftmost + 1;
                m.erase(s[leftmost]);
            }
            
            longest = max(longest, right-left);
        }
        
        return longest;
    }
};