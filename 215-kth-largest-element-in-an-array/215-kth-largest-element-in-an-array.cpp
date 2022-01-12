class Solution {
private:
    vector<int> nums;
    
    int partition(int left, int right, int pivot)
    {
        int store = left;
        swap(nums[pivot], nums[right]);
        
        for(int i=left; i<=right; i++)
        {
            if(nums[i] < nums[right])
            {
                swap(nums[i], nums[store]);
                store++;
            }
        }
        swap(nums[store], nums[right]);
        return store;
    }
    
    void quickSelect(int left, int right, int k)
    {
        if(left == right)
            return;
        
        int pivot = left + rand() % (right - left + 1);
        pivot = partition(left, right, pivot);
        
        if(pivot == k)
            return;
        
        if(pivot > k)
            quickSelect(left, pivot-1, k);
        else
            quickSelect(pivot+1, right, k);
    }
    
public:
    int findKthLargest(vector<int>& nums, int k) {
        this->nums = nums;
        quickSelect(0, nums.size()-1, nums.size()-k);
        
        return this->nums[nums.size()-k];
    }
};