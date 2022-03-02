class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int sz = nums.size();
        int left = 0, right = sz - 1;
        vector<int> ans(sz);
        
        for(int i = sz - 1; i >= 0; i--) {
            int n;
            if(abs(nums[left]) < abs(nums[right]))
                n = nums[right--];
            else
                n = nums[left++];
            
            ans[i] = n * n;
        }
        
        return ans;
    }
};