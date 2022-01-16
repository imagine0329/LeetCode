class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int cur = 0;
        while(cur != nums[cur]) {
            int next = nums[cur];
            nums[cur] = cur;
            cur = next;
        }
        
        return cur;
    }
};