class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int i = 0, even = 0, odd = 0;
        while(i < nums.size()) {
            while(even < nums.size() && (nums[even] & 1)) even++;
            swap(nums[i++], nums[even++]);
            while(odd < nums.size() && ((nums[odd] & 1) == 0)) odd++;
            swap(nums[i++], nums[odd++]);
        }
        
        return nums;
    }
};