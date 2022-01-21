class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums);
        return nums;
    }
    
private:
    void mergeSort(vector<int>& nums) {
        int n = nums.size();
        for(int size = 1; size < n; size *= 2) {
            for(int left = 0; left < n - size; left += 2 * size) {
                int mid = left + size - 1;
                int right = min(left + (2 * size) - 1, n - 1);
                merge(nums, left, mid, right);
            }
        }
    }
    
    void merge(vector<int>& nums, int left, int mid, int right) {
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