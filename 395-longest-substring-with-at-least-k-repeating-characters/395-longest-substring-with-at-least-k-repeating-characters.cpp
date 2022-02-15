class Solution {
public:
    int longestSubstring(string s, int k) {
        int longest = 0;
        
        for(int i = 0; i < s.length(); i++) {
            vector<int> freq(26, 0);
            for(int j = i; j < s.length(); j++) {
                freq[s[j] - 'a']++;
                if(checkFreq(freq, k))
                    longest = max(longest, j - i + 1);
            }
        }
        
        return longest;
    }
    
    bool checkFreq(vector<int>& freq, int k) {
        for(auto f : freq) {
            if(f > 0 && f < k)
                return false;
        }
        return true;
    }
};