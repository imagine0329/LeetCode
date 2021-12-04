class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if(s.length() < 3)
            return s.length();
        
        unordered_map<char, int> m;
        int left = 0, right = 0;
        int len = 0;
        
        while(right < s.length())
        {
            m[s[right]] = right;
            right++;
            
            if(m.size() > 2)
            {
                int leftmost = INT_MAX;
                for(auto n : m)
                    leftmost = min(leftmost, n.second);
                
                m.erase(s[leftmost]);
                left = leftmost + 1;
            }
            
            len = max(len, right - left);
        }
        
        return len;
    }
};