class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> m;
        
        for(int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            sort(str.begin(), str.end());
            m[str].push_back(strs[i]);
        }
        
        for(auto v : m)
            ans.push_back(v.second);
        
        return ans;
    }
};