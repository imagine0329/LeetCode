class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> m;
        
        for(auto str : strs) {
            string s = str;
            sort(s.begin(), s.end());
            m[s].push_back(str);
        }
        
        for(auto e : m)
            ans.push_back(e.second);
        
        return ans;
    }
};