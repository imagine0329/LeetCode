class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        
        backtracking(ans, v, nums, 0);
        
        return ans;
    }
    
    void backtracking(vector<vector<int>>& ans, vector<int>& v, vector<int>& nums, int i)
    {
        if(i >= nums.size())
        {
            ans.push_back(v);
            return;
        }
        
        for(int k = i; k < nums.size(); k++)
        {
            v.push_back(nums[k]);
            swap(nums[i], nums[k]);
            backtracking(ans, v, nums, i+1);
            swap(nums[i], nums[k]);
            v.pop_back();
        }
    }
    
};