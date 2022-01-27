class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        int longest = 0;
        vector<int> count(26, 0);
        
        for(int start = 0; start < n; start++) {
            memset(count.data(), 0, sizeof(int)*count.size());
            for(int end = start; end < n; end++) {
                count[s[end] - 'a']++;
                if(isValid(k, count))
                    longest = max(longest, end - start + 1);
            }
        }
        
        return longest;
    }
    
    bool isValid(int k, vector<int>& count) {
        for(auto c : count) {
            if(c != 0 && c < k)
                return false;
        }
        
        return true;
    }
};