class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        
        for(int i=0; i<nums.size() && nums[i] <= 0; i++)
        {
            if(i == 0 || nums[i-1] != nums[i])
                findTwoSum(nums, i+1, ans);
        }    
        
        return ans;
    }
    
    void findTwoSum(vector<int>& nums, int start, vector<vector<int>>& ans)
    {
        int left = start, right = nums.size()-1;
        int num = 0 - nums[start-1];
        
        while(left < right)
        {
            int twoSum = nums[left] + nums[right];
            
            if(twoSum < num)
                left++;
            else if(twoSum > num)
                right--;
            else
            {
                ans.push_back({nums[start-1], nums[left++], nums[right--]});
                while(left < right && nums[left] == nums[left-1])
                    left++;
            }
        }
        
        return;
    }
};