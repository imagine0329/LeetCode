// quick sort
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
    
private:
    void quickSort(vector<int>& nums, int left, int right) {
        if(left >= right)
            return;
        int mid = partition(nums, left, right);
        quickSort(nums, left, mid);
        quickSort(nums, mid + 1, right);
    }
    
    int partition(vector<int>& nums, int left, int right) {
        int mid = left + (right - left) / 2;
        swap(nums[left], nums[mid]);
        int pivot = nums[left];
        
        while(left < right) {
            while(left < right && nums[right] >= pivot) right--;
            nums[left] = nums[right];
            while(left < right && nums[left] <= pivot) left++;
            nums[right] = nums[left];
        }
        
        nums[left] = pivot;
        return left;
    }
};