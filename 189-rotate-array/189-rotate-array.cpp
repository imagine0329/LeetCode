class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        
        int count = 0;
        for(int start=0; count<nums.size(); start++)
        {
            int current_idx = start;
            int prev_val = nums[start];
            do{
                int next_idx = (current_idx + k) % nums.size();
                int next_val = nums[next_idx];
                nums[next_idx] = prev_val;
                prev_val = next_val;
                current_idx = next_idx;
                count++;
            }while(current_idx != start);
        }
    }
};