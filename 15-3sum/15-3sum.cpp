class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> s;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            int target = 0 - nums[i];
            int left = i + 1, right = nums.size() - 1;
            while(left < right) {
                int sum = nums[left] + nums[right];
                if(sum == target)
                    s.insert({nums[i], nums[left++], nums[right--]});
                else if(sum < target) left++;
                else right--;
            }
        }
        
        return vector<vector<int>>(s.begin(), s.end());
    }
};