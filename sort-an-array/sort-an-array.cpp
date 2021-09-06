class Solution {
public:
    
    void merge(vector<int>& nums, int begin, int mid, int end)
    {
        vector<int> temp(end-begin+1);
        int i = begin;
        int j = mid + 1;
        int k = 0;
        
        while(i <= mid && j <= end)
        {
            if(nums[i] <= nums[j])  temp[k++] = nums[i++];
            else    temp[k++] = nums[j++];
        }
        
        while(i <= mid)   temp[k++] = nums[i++];
        while(j <= end) temp[k++] = nums[j++];
        for(i = 0; i < k; i++)  nums[begin + i] = temp[i];
    }
    
    void mergeSort(vector<int>& nums, int begin, int end)
    {
        if(begin >= end)  return;
        int mid = (begin + end) / 2;
        mergeSort(nums, begin, mid);
        mergeSort(nums, mid+1, end);
        merge(nums, begin, mid, end);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};