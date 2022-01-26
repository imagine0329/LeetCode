class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int largest = INT_MIN;
        int maximum = 1, minimum = 1;
        
        for(int i = 0; i < nums.size(); i++) {
            int product1 = maximum * nums[i], product2 = minimum * nums[i];
            maximum = max(nums[i], max(product1, product2));
            minimum = min(nums[i], min(product1, product2));
            largest = max(largest, maximum);
        }
        
        return largest;
    }
};