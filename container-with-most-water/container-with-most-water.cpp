class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int maxWater = INT_MIN;
        while(left < right)
        {
            int area = (right-left) * min(height[left], height[right]);
            maxWater = max(maxWater, area);
            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        
        return maxWater;
    }
};