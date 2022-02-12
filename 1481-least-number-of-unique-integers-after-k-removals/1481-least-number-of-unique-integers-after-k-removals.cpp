class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> m;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(auto n : arr)
            m[n]++;
        for(auto n : m)
            pq.push(n.second);
        
        while(k > 0) {
            k -= pq.top();
            if(k >= 0)
                pq.pop();
        }
        
        return pq.size();
    }
};