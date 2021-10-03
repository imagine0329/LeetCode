class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = i+1;
        while(j < nums.size())
        {
            if(nums[i] == 0)
            {
                while(j < nums.size() && nums[j] == 0)
                    j++;
                
                if(j < nums.size())
                    swap(nums[i], nums[j]);
                else
                    break;
            }
            
            i++;
            j = i+1;
        }
    }
};