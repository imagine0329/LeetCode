class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mid = nums[nums.size() / 2];
        
        int moves = 0;
        for(auto n : nums)
            moves += abs(n - mid);
        
        return moves;
    }
};