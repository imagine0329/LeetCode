class Solution {
private:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right];
        int i = left;
        for(int j = left; j <= right; j++) {
            if(nums[j] < pivot)
                swap(nums[j], nums[i++]);
        }
        
        swap(nums[i], nums[right]);
        return i;
    }
    
    int quickSelect(vector<int>& nums, int left, int right, int k) {
        if(left == right)
            return nums[left];
        
        int pivot = partition(nums, left, right);
        if(k == pivot) return nums[k];
        else if(k < pivot) return quickSelect(nums, left, pivot - 1, k);
        else return quickSelect(nums, pivot + 1, right, k);
    }
    
public:
    int minMoves2(vector<int>& nums) {
        int moves = 0;
        int median = quickSelect(nums, 0, nums.size() - 1, nums.size() / 2);
        
        for(auto n : nums)
            moves += labs(median - n);
        
        return moves;
    }
};