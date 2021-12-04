class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        map<int, int> m;
        
        for(auto n : arr1)
            m[n]++;
        
        for(auto n : arr2)
            m[n]++;
        
        for(auto n : arr3)
            m[n]++;
        
        vector<int> ans;
        for(auto n : m)
        {
            if(n.second == 3)
                ans.push_back(n.first);
        }
        
        return ans;
    }
};