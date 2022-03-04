class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ns = s.length(), np = p.length();
        if(ns < np) return {};
        
        vector<int> sCount(26, 0), pCount(26, 0);
        
        for(auto c : p)
            pCount[c - 'a']++;
        
        vector<int> ans;
        for(int i = 0; i < ns; i++) {
            sCount[s[i] - 'a']++;
            if(i >= np)
                sCount[s[i - np] - 'a']--;
            if(sCount == pCount)
                ans.push_back(i - np + 1);
        }
        return ans;
    }
};