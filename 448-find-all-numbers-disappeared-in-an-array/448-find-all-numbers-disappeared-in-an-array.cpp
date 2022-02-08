class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        
        for(int i = 0; i < nums.size(); i++)
            recursion(nums, i);
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != i + 1)
                ans.push_back(i + 1);
        }
        
        return ans;
    }
    
    void recursion(vector<int>& nums, int i) {
        if(nums[i] == nums[nums[i] - 1] || nums[i] == i + 1)
            return;
        
        swap(nums[i], nums[nums[i] - 1]);
        recursion(nums, i);
    }
};