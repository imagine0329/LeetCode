class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        
        backtracking(ans, nums, 0);
        
        return ans;
    }
    
    void backtracking(vector<vector<int>>& ans, vector<int>& nums, int idx)
    {
        if(idx == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        
        unordered_set<int> s;
        for(int i=idx; i<nums.size(); i++)
        {
            //if(i != idx && nums[i] == nums[idx])
            //    continue;
            if(s.count(nums[i]) == 1)
                continue;
            
            s.insert(nums[i]);
            
            swap(nums[i], nums[idx]);
            backtracking(ans, nums, idx+1);
            swap(nums[i], nums[idx]);
        }
    }
};