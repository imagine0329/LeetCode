class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int water = 0;
        int min_height = 0;
        
        while(left < right) {
            while(left < right && height[left] <= min_height)
                water += (min_height - height[left++]);
            while(left < right && height[right] <= min_height)
                water += (min_height - height[right--]);
            min_height = min(height[left], height[right]);
        }
        
        return water;
    }
};