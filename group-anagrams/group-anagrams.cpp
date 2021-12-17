class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<int>> m;
        
        for(int i=0; i<strs.size(); i++)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            m[s].push_back(i);
        }
        
        for(auto s : m)
        {
            vector<string> v;
            for(auto idx : s.second)
                v.push_back(strs[idx]);
            ans.push_back(v);
        }
        
        return ans;
    }
};