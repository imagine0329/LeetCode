class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        set<vector<int>> ans;
        vector<int> nums;
        
        backtracking(ans, nums, candidates, target, 0);
        
        return vector<vector<int>>(ans.begin(), ans.end());
    }
    
    void backtracking(set<vector<int>>& ans, vector<int>& nums, vector<int>& candidates, int remain, int start)
    {
        if(remain == 0)
        {
            ans.insert(nums);
            return;
        }
        
        for(int i=start; i<candidates.size(); i++)
        {
            if(remain - candidates[i] < 0)
                continue;
            
            if(i != start && candidates[i] == candidates[i-1])
                continue;
            
            nums.push_back(candidates[i]);
            backtracking(ans, nums, candidates, remain-candidates[i], i+1);
            nums.pop_back();
        }
    }
};