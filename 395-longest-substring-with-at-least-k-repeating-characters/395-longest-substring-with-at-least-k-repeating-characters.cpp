class Solution {
public:
    int longestSubstring(string s, int k) {
        return longestSubstring(s, k, 0, s.length() - 1);
    }
    
    int longestSubstring(string s, int k, int start, int end) {
        if(start > end)
            return 0;
        
        unordered_map<char, vector<int>> m;
        for(int i = start; i <= end; i++)
            m[s[i]].push_back(i);
        
        int mid = findInvalid(m, k);
        if(mid == -1)
            return end - start + 1;
        
        return max(longestSubstring(s, k, start, mid - 1), longestSubstring(s, k, mid + 1, end));
    }
    
    int findInvalid(unordered_map<char, vector<int>>& m, int k) {
        for(auto n : m) {
            if(n.second.size() < k)
                return n.second.front();
        }
        
        return -1;
    }
};