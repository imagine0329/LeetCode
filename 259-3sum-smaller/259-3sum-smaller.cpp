class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0)
            return 0;
        
        sort(nums.begin(), nums.end());
        
        int num = 0;
        for(int i=0; i<n-2; i++) {
            for(int j=i+1; j<n-1; j++) {
                int k = binarySearch(nums, target-nums[i]-nums[j], j);
                num += k - j;
            }
        }
        
        return num;
    }
    
    int binarySearch(vector<int>& nums, int target, int start) {
        int left = start, right = nums.size() - 1;
        
        while(left < right) {
            int mid = (left + right + 1)/2;
            
            if(target - nums[mid] <= 0)
                right = mid - 1;
            else
                left = mid;
        }
        
        return left;
    }
    
};