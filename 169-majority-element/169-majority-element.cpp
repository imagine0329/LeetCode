class Solution {
private:
    int countNum(vector<int>& nums, int num, int lo, int hi)
    {
        int count = 0;
        for(int i=lo; i<=hi; i++)
        {
            if(nums[i] == num)
                count++;
        }
        
        return count;
    }
    
    int majority(vector<int>& nums, int lo, int hi)
    {
        if(lo == hi)
            return nums[lo];
        
        int mid = lo + (hi-lo)/2;
        int left = majority(nums, lo, mid);
        int right = majority(nums, mid+1, hi);
        
        if(left == right)
            return left;
        
        int l_count = countNum(nums, left, lo, hi);
        int r_count = countNum(nums, right, lo, hi);
        
        return l_count > r_count ? left : right;
    }
    
public:
    int majorityElement(vector<int>& nums) {
        return majority(nums, 0, nums.size()-1);
    }
    
    
};