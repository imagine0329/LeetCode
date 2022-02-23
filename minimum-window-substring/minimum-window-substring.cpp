class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> dict(128, 0);
        for(auto c : t) dict[c]++;
        
        int len = INT_MAX, start = 0;
        int remain = t.length();
        int left = 0, right = 0;
        
        while(right < s.length()) {
            if(--dict[s[right++]] >= 0) remain--;
            while(remain == 0) {
                if(len > right - left) {
                    len = right - left;
                    start = left;
                }
                if(++dict[s[left++]] > 0) remain++;
            }
        }
        
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};