class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> m;
        
        for(auto str : strs) {
            vector<int> count(26);
            for(auto c : str)
                count[c - 'a']++;
            
            string s;
            for(auto n : count)
                s += (n + '0');
            m[s].push_back(str);
        }
        
        for(auto e : m)
            ans.push_back(e.second);
        
        return ans;
    }
};