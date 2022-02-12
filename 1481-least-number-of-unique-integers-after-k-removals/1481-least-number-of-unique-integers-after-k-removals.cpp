class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> m;
        
        for(auto n : arr)
            m[n]++;
        
        queue<int> q;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for(auto n : m)
            pq.push({n.second, n.first});
        
        int left = k;
        while(!pq.empty()) {
            auto x = pq.top(); pq.pop();
            if(left < x.first)
                break;
            else if(left == x.first) {
                q.push(x.second);
                break;
            }
            
            left -= x.first;
            q.push(x.second);
        }
        
        return m.size() - q.size();;
    }
};