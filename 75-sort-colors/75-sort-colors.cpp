class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0, curr = 0, p2 = nums.size()-1;
        
        while(curr <= p2){
            if(nums[curr] == 0)
                swap(nums[p0++], nums[curr++]);
            else if(nums[curr] == 2)
                swap(nums[p2--], nums[curr]);
            else
                curr++;
        }
    }
};