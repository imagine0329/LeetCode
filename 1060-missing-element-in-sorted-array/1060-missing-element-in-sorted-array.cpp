class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        for(int i = 1; i < nums.size(); i++) {
            int gap = nums[i] - nums[i-1] - 1;
            if(gap >= k)
                return nums[i-1] + k;
            else
                k -= gap;
        }
        
        return nums.back() + k;
    }
};