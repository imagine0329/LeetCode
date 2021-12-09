class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> comb;
        
        sort(nums.begin(), nums.end());
        backtracking(ans, comb, nums, 0);
        
        return ans;
    }
    
    void backtracking(vector<vector<int>>& ans, vector<int>& comb, vector<int>& nums, int index)
    {
        ans.push_back(comb);
        
        for(int i=index; i<nums.size(); i++)
        {
            if(i != index && nums[i] == nums[i-1])
                continue;
            
            comb.push_back(nums[i]);
            backtracking(ans, comb, nums, i+1);
            comb.pop_back();
        }
    }
};
