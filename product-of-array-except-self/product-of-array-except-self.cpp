class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        
        ans.push_back(1);
        for(int i = 1; i < nums.size(); i++)
            ans.push_back(ans[i-1] * nums[i-1]);
        
        int x = 1;
        for(int i = ans.size() - 1; i >= 0; i--)
        {
            ans[i] *= x;
            x *= nums[i];
        }
        
        return ans;
    }
};