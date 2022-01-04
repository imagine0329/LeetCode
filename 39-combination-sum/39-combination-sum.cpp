class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> ans;
        vector<int> nums;
        
        backtracking(candidates, target, 0, ans, nums);
        
        return vector<vector<int>>(ans.begin(), ans.end());
    }
    
    void backtracking(vector<int>& candidates, int target, int sum, set<vector<int>>& ans, vector<int>& nums) {
        if(sum == target)
        {
            vector<int> temp = nums;
            sort(temp.begin(), temp.end());
            ans.insert(temp);
            return;
        }
        
        for(int i=0; i<candidates.size(); i++)
        {
            if(sum + candidates[i] > target)
                continue;
            
            sum += candidates[i];
            nums.push_back(candidates[i]);
            backtracking(candidates, target, sum, ans, nums);
            nums.pop_back();
            sum -= candidates[i];
        }
    }
};


