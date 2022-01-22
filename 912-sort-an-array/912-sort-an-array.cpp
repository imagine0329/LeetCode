class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums);
        return nums;
    }
    
private:
    void heapSort(vector<int>& nums) {
        int size = nums.size();
        for(int i = size / 2 - 1; i >= 0; i--)
            heapify(nums, size, i);
        
        for(int i = size - 1; i > 0; i--) {
            swap(nums[0], nums[i]);
            heapify(nums, i, 0);
        }
    }
    
    void heapify(vector<int>& nums, int size, int i) {
        int largest = i;
        int l_child = 2 * i + 1, r_child = 2 * i + 2;
        
        if(l_child < size && nums[l_child] > nums[largest])
            largest = l_child;
        if(r_child < size && nums[r_child] > nums[largest])
            largest = r_child;
        
        if(largest != i) {
            swap(nums[i], nums[largest]);
            heapify(nums, size, largest);
        }
    }
};