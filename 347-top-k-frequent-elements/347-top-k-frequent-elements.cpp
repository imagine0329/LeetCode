class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, int> m;
        
        for(auto n : nums)
            m[n]++;
        
        for(auto e : m) {
            pq.push({e.second, e.first});
            if(pq.size() > k)
                pq.pop();
        }
        
        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};