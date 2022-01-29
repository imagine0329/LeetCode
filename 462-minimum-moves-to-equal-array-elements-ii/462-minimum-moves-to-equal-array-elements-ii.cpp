class Solution {
public:
    int minMoves2(vector<int>& nums) {
        long moves = INT_MAX;
        
        for(auto n : nums) {
            long count = 0;
            for(auto k : nums)
                count += labs(k - n);
            
            moves = min(moves, count);
        }
        
        return (int)moves;
    }
};