class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> q;
        
        for(auto n : nums)
            m[n]++;
        
        for(auto n : m) {
            q.push({n.second, n.first});
            if(q.size() > k)
                q.pop();
        }
        
        vector<int> ans;
        while(!q.empty()) {
            int n = q.top().second; q.pop();
            ans.push_back(n);
        }
        
        return ans;
    }
};