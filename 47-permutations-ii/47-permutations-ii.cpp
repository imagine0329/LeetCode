class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        
        backtracking(nums, 0, ans);
        
        return ans;
    }
    
    void backtracking(vector<int>& nums, int start, vector<vector<int>>& ans)
    {
        if(start == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        
        unordered_set<int> s;
        for(int i=start; i<nums.size(); i++)
        {
            if(s.count(nums[i]) == 1)
                continue;
            
            s.insert(nums[i]);
            swap(nums[i], nums[start]);
            backtracking(nums, start+1, ans);
            swap(nums[i], nums[start]);
        }
    }
};