class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        
        vector<int> extra(nums.size());
        for(int i=0; i<nums.size(); i++)
            extra[(i+k)%nums.size()] = nums[i];
        
        nums = extra;
    }
};