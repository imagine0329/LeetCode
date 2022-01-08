class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<vector<int>> subsets;
        sort(nums.begin(), nums.end());
        
        ret.push_back({});
        for(int i=0; i<nums.size(); i++)
        {
            vector<vector<int>> temp;
            if(i != 0 && nums[i] == nums[i-1])
                temp = subsets;
            else
                temp = ret;
            
            subsets.clear();
            for(auto s : temp)
            {
                s.push_back(nums[i]);
                subsets.push_back(s);
                ret.push_back(s);
            }
        }
        
        return ret;
    }
    
};
