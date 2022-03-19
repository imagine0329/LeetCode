class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        quickSelect(nums, nums.size() - k, 0, nums.size() - 1);
        return nums[nums.size() - k];
    }
    
    void quickSelect(vector<int>& nums, int k, int left, int right) {
        if(left == right) return;
        int pivot = left + (right - left) / 2;
        pivot = partition(nums, left, right, pivot);
        
        if(pivot == k) return;
        if(pivot < k) quickSelect(nums, k, pivot + 1, right);
        else quickSelect(nums, k, left, pivot - 1);
    }
    
    int partition(vector<int>& nums, int left, int right, int pivot) {
        int i = left, store = left;
        swap(nums[right], nums[pivot]);
        
        while(i < right) {
            if(nums[right] > nums[i]) {
                swap(nums[store], nums[i]);
                store++;
            }
            
            i++;
        }
        swap(nums[store], nums[right]);
        return store;
    }
};