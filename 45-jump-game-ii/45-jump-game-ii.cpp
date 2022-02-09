class Solution {
public:
    int jump(vector<int>& nums) {
        int count = 0, farthest = 0, end = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            farthest = max(farthest, i + nums[i]);
            if(i == end) {
                count++;
                end = farthest;
            }
        }
        
        return count;
    }
};