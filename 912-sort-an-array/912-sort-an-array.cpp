// quick sort
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
    
private:
    void mergeSort(vector<int>& nums, int left, int right) {
        if(left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, right);
    }
    
    void merge(vector<int>& nums, int left, int right) {
        int mid = left + (right - left) / 2;
        vector<int> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;
        while(i <= mid || j <= right) {
            if(i > mid || (j <= right && nums[i] > nums[j]))
                temp[k++] = nums[j++];
            else
                temp[k++] = nums[i++];
        }
        
        copy(temp.begin(), temp.end(), nums.begin() + left);
    }
};