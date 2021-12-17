class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 2)
            return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        
        for(int i=0; i<nums.size()-2; i++)
        {
            if(i != 0 && nums[i] == nums[i-1])
                continue;
            
            twoSum(ans, nums, i);
        }
        
        return ans;
    }
    
    void twoSum(vector<vector<int>>& ans, vector<int>& nums, int i)
    {
        int target = 0 - nums[i];
        int left = i + 1, right = nums.size() - 1;
        
        while(left < right)
        {
            int sum = nums[left] + nums[right];
            if(sum == target)
            {
                ans.push_back({nums[i], nums[left++], nums[right--]});
                while(left < right && nums[left] == nums[left-1])
                    left++;
            }
            else if(sum < target)
                left++;
            else
                right--;
        }
    }
};