class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> m;
        vector<int> count(26, 0);
        
        for(auto s : strs) {
            vector<int> count(26, 0);
            for(auto c : s)
                count[c - 'a']++;
            string str;
            for(auto n : count)
                str += (n + '0');
            m[str].push_back(s);
        }
        
        for(auto v : m)
            ans.push_back(v.second);
        
        return ans;
    }
};