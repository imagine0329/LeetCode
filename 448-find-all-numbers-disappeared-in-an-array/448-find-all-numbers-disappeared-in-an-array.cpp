class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        
        for(int i = 1; i <= nums.size(); i++) {
            while(nums[i - 1] != nums[nums[i - 1] - 1] && nums[i - 1] != i)
                swap(nums[i - 1], nums[nums[i - 1] - 1]);
        }
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != i + 1)
                ans.push_back(i + 1);
        }
        
        return ans;
    }
};