class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        selectionSort(nums);
        int diff = INT_MAX, ans;
        
        for(int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1, right = nums.size() - 1;
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if(diff > abs(target - sum)) {
                    diff = abs(target - sum);
                    ans = sum;
                }
                
                if(sum > target)
                    right--;
                else
                    left++;
            }
        }
        
        return ans;
    }
    
    void selectionSort(vector<int>& nums) {
        for(int i = 0; i < nums.size() - 1; i++) {
            int least = i;
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[least] > nums[j])
                    least = j;
            }
            swap(nums[least], nums[i]);
        }
    }
};