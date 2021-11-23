class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        vector<vector<int>> ans;
        map<int, priority_queue<int>> m;
        
        for(auto n : items)
            m[n[0]].push(n[1]);
        
        for(auto n : m)
        {
            vector<int> temp;
            temp.push_back(n.first);
            
            int sum = 0;
            for(int i=0; i<5; i++)
            {    
                sum += n.second.top();
                n.second.pop();
            }
            
            temp.push_back(sum/5);
            
            ans.push_back(temp);
        }
        
        return ans;
    }
};