class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        
        ans.push_back({});
        
        backtracking(ans, v, nums, 0);
        
        return ans;
    }
    
    void backtracking(vector<vector<int>>& ans, vector<int>& v, vector<int>& nums, int i)
    {
        if(i >= nums.size())
            return;
        
        for(int k = i; k < nums.size(); k++)
        {
            v.push_back(nums[k]);
            ans.push_back(v);
            backtracking(ans, v, nums, k+1);
            v.pop_back();
        }
    }
};