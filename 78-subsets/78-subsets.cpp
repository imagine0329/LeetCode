class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> v1, v2;
        v1.push_back({});
        v2.push_back({});
        
        for(auto n : nums)
        {
            for(auto v : v1)
            {
                vector<int> temp;
                temp = v;
                temp.push_back(n);
                v2.push_back(temp);
            }
            
            v1 = v2;
        }
        
        return v2;
    }
};