class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, multiset<int, greater<int>>> m;
        
        for(auto item : items)
            m[item[0]].insert(item[1]);
        
        vector<vector<int>> ans;
        for(auto n : m) {
            auto it = n.second.begin();
            int sum = 0;
            for(int i = 0; i < 5; i++, ++it)
                sum += *it;
            
            ans.push_back({n.first, sum / 5});
        }
        
        return ans;
    }
};