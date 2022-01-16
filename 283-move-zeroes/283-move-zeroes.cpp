class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nonZeroFoundAt = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] != 0)
                nums[nonZeroFoundAt++] = nums[i];
        }
        
        for(int i=nonZeroFoundAt; i<nums.size(); i++)
            nums[i] = 0;
    }
};