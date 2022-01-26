class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int largest = INT_MIN;
        vector<int> maximum(nums.size() + 1, 1), minimum(nums.size() + 1, 1);
        
        for(int i = 0; i < nums.size(); i++) {
            int product1 = maximum[i] * nums[i], product2 = minimum[i] * nums[i];
            maximum[i + 1] = max(nums[i], max(product1, product2));
            minimum[i + 1] = min(nums[i], min(product1, product2));
            largest = max(largest, maximum[i + 1]);
        }
        
        return largest;
    }
};