class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int missing = 0;
        
        for(int i=0; i<=n; i++)
            missing ^= i;
        for(auto i : nums)
            missing ^= i;
        
        return missing;
    }
};