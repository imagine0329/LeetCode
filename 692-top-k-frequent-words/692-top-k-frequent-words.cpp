struct Compare {
    bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
        if(a.first == b.first)
            return a.second < b.second;
        return a.first > b.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> q;
        
        for(auto& s : words)
            m[s]++;
        
        for(auto e : m) {
            q.push({e.second, e.first});
            if(q.size() > k)
                q.pop();
        }
        
        vector<string> ans;
        while(!q.empty()) {
            ans.insert(ans.begin(), q.top().second);
            q.pop();
        }
        
        return ans;
    }
};