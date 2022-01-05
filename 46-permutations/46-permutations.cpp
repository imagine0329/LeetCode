class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> perm;
        
        backtracking(nums, 0, ans, perm);
        
        return ans;
    }
    
    void backtracking(vector<int>& nums, int start, vector<vector<int>>& ans, vector<int>& perm)
    {
        if(start == nums.size())
        {
            ans.push_back(perm);
            return;
        }

        for(int i=start; i<nums.size(); i++)
        {
            perm.push_back(nums[i]);
            swap(nums[start], nums[i]);
            backtracking(nums, start+1, ans, perm);
            swap(nums[start], nums[i]);
            perm.pop_back();
        }
    }
};