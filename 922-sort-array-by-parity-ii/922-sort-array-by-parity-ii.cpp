class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int even = 0, odd = 1;
        while(even < nums.size()) {
            if(nums[even] & 1) {
                while(nums[odd] & 1) odd += 2;
                swap(nums[even], nums[odd]);
            }
            even += 2;
        }
        
        return nums;
    }
};