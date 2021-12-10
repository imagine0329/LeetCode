class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> perm;
        
        backtracking(ans, perm, nums, 0);
        
        return ans;
    }
    
    void backtracking(vector<vector<int>>& ans, vector<int>& perm, vector<int>& nums, int index)
    {
        if(index == nums.size())
        {
            ans.push_back(perm);
            return;
        }
        
        vector<int> temp = nums;
        
        for(int i=index; i<nums.size(); i++)
        {
            perm.push_back(nums[i]);
            swap(nums[index], nums[i]);
            backtracking(ans, perm, nums, index+1);
            swap(nums[index], nums[i]);
            perm.pop_back();
        }
    }
};