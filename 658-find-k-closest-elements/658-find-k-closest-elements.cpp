class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if(arr.front() > x)
            return vector<int>(arr.begin(), arr.begin() + k);
        else if(arr.back() < x)
            return vector<int>(arr.end() - k, arr.end());
        
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for(auto n : arr) {
            q.push({abs(x - n), n});
        }
        
        for(int i = 0; i < k; i++)
        {
            ans.push_back(q.top().second);
            q.pop();
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};