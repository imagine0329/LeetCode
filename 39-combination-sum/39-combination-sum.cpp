class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> nums;
        
        backtracking(candidates, target, 0, 0, ans, nums);
        
        return ans;
    }
    
    void backtracking(vector<int>& candidates, int target, int sum, int start, vector<vector<int>>& ans, vector<int>& nums) {
        if(sum == target)
        {
            ans.push_back(nums);
            return;
        }
        
        for(int i=start; i<candidates.size(); i++)
        {
            if(sum + candidates[i] > target)
                continue;
            
            sum += candidates[i];
            nums.push_back(candidates[i]);
            backtracking(candidates, target, sum, i, ans, nums);
            nums.pop_back();
            sum -= candidates[i];
        }
    }
};


