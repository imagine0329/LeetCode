class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int size = s.length();
        if(size * k == 0)
            return 0;
        
        int left = 0, right = 0, max_length = 1;
        map<char, int> m;
        
        while(right < size)
        {
            m[s[right]] = right;
            right++;
            
            if(m.size() == k + 1)
            {
                int lowest_index = INT_MAX;
                for(auto n : m)
                    lowest_index = min(lowest_index, n.second);
                
                m.erase(s[lowest_index]);
                left = lowest_index + 1;
            }
            
            max_length = max(max_length, right - left);
        }
        
        return max_length;
    }
};