class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        vector<int> v;
        
        for(int i = nums.size() - k; i < nums.size(); i++)
            v.push_back(nums[i]);
        for(int i = 0; i < nums.size() - k; i++)
            v.push_back(nums[i]);
        nums = v;
    }
    
};