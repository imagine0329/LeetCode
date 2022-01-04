class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> nums;
        
        backtracking(candidates, target, 0, ans, nums);
        
        return ans;
    }
    
    void backtracking(vector<int>& candidates, int sum, int start, vector<vector<int>>& ans, vector<int>& nums) {
        if(sum == 0)
        {
            ans.push_back(nums);
            return;
        }
        
        for(int i=start; i<candidates.size(); i++)
        {
            if(sum - candidates[i] < 0)
                continue;
            
            nums.push_back(candidates[i]);
            backtracking(candidates, sum-candidates[i], i, ans, nums);
            nums.pop_back();
        }
    }
};


