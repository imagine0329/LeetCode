class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        int n = nums.size()-2;
        for(int i=0; i<n; i++)
        {
            if(i != 0 && nums[i] == nums[i-1])
                continue;
            
            int left = i+1, right = nums.size()-1;
            while(left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == 0)
                {
                    ans.push_back({nums[i], nums[left++], nums[right--]});
                    while(left < right && nums[left] == nums[left-1])
                        left++;
                }
                else if(sum > 0)
                    right--;
                else
                    left++;
            }
        }
        
        return ans;
    }
    
};