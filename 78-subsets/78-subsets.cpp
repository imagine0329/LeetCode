class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        vector<vector<int>> ans;
        ans.push_back({});
        
        backtracking(nums, ans, v, 0);
        
        return ans;
    }
    
    void backtracking(vector<int>& nums, vector<vector<int>>& ans, vector<int>& v, int start)
    {
        if(start == nums.size())
            return;
        
        for(int i=start; i<nums.size(); i++)
        {
            v.push_back(nums[i]);
            ans.push_back(v);
            backtracking(nums, ans, v, i+1);
            v.pop_back();
        }
    }
};