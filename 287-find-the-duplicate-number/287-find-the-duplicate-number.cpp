class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int duplicate = -1;
        
        for(auto n : nums) {
            int cur = abs(n);
            if(nums[cur] < 0) {
                duplicate = cur;
                break;
            }
            nums[cur] *= -1;
        }
        
        for(auto n : nums)
            n = abs(n);
        
        return duplicate;
    }
};