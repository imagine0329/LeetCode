struct Compare{
    bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
        if(a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    }
};

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> q;
        
        for(auto n : arr) {
            q.push({abs(n - x), n});
            if(q.size() > k)
                q.pop();
        }
        
        vector<int> ans;
        while(!q.empty()) {
            ans.push_back(q.top().second);
            q.pop();
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};