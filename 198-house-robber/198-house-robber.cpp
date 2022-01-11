class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        int nextPlusOne = 0;
        int next = nums[n-1];
        
        for(int i=n-2; i>=0; i--)
        {
            int current = max(next, nextPlusOne + nums[i]);
            nextPlusOne = next;
            next = current;
        }
        
        return next;
    }
};