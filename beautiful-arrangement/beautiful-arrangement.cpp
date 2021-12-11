class Solution {
public:
    int countArrangement(int n) {
        int count = 0;
        vector<int> nums;
        
        for(int i=0; i<n; i++)
            nums.push_back(i+1);
        
        backtracking(count, nums, n, 0);
        
        return count;
    }
    
    void backtracking(int& count, vector<int>& nums, int n, int start)
    {
        if(start == n)
        {
            count++;
            return;
        }
        
        for(int i=start; i<n; i++)
        {
            swap(nums[i], nums[start]);
            if((nums[start] % (start+1)) == 0 || ((start+1) % nums[start]) == 0)
                backtracking(count, nums, n, start+1);
            swap(nums[i], nums[start]);
        }
    }
};