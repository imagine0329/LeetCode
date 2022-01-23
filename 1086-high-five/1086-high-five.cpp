class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, priority_queue<int, vector<int>, greater<int>>> m;
        
        for(auto item : items) {
            int id = item[0];
            int score = item[1];
            
            m[id].push(score);
            if(m[id].size() > 5)
                m[id].pop();
        }
        
        vector<vector<int>> ans;
        for(auto n : m) {
            int sum = 0;
            for(int i = 0; i < 5; i++) {
                sum += n.second.top();
                n.second.pop();
            }
            ans.push_back({n.first, sum / 5});
        }
        
        return ans;
    }
};