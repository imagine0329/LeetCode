class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> chars(128, -1);
        
        int left = 0, right = 0;
        int ans = 0;
        
        while(right < s.length())
        {
            char r = s[right];
            int index = chars[r];
            if(index != -1 && index >= left && index < right)
                left = index + 1;
            
            ans = max(ans, right-left+1);
            chars[r] = right;
            right++;
        } 
        
        return ans;
    }
};