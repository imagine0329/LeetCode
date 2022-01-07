class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> subset;
        
        backtracking(nums, ans, subset, 0);
        
        return ans;
    }
    
    void backtracking(vector<int>& nums, vector<vector<int>>& ans, vector<int>& subset, int start)
    {
        ans.push_back(subset);
        for(int i=start; i<nums.size(); i++)
        {
            if(i != start && nums[i] == nums[i-1])
                continue;
            
            subset.push_back(nums[i]);
            backtracking(nums, ans, subset, i+1);
            subset.pop_back();
        }
    }
    
};
