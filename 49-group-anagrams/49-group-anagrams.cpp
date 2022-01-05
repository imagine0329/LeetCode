class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<int>> m;
        
        for(int i=0; i<strs.size(); i++)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            m[s].push_back(i);
        }
        
        vector<vector<string>> ans(m.size());
        int k = 0;
        for(auto n : m)
        {
            for(int i=0; i<n.second.size(); i++)
                ans[k].push_back(strs[n.second[i]]);
            
            k++;
        }
        
        return ans;
    }

};