class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        if(n == 0 || k > n) return 0;
        
        unordered_map<char, int> m;
        for(auto c : s)
            ++m[c];
        
        int mid = 0;
        while(mid < n && m[s[mid]] >= k) mid++;
        if(mid == n)
            return n;
        int left = longestSubstring(s.substr(0, mid), k);
        while(mid < n && m[s[mid]] < k) mid++;
        int right = longestSubstring(s.substr(mid), k);
        return max(left, right);
    }
    
};