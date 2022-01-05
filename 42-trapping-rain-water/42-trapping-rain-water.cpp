class Solution {
public:
    int trap(vector<int>& height) {
        int area = 0;
        
        int left = 0, right = height.size()-1;
        int l_max = 0, r_max = 0;
        while(left < right)
        {
            if(height[left] < height[right])
            {
                height[left] >= l_max ? l_max = height[left] : area += (l_max - height[left]);
                left++;
            }
            else
            {
                height[right] >= r_max ? r_max = height[right] : area += (r_max - height[right]);
                right--;
            }
        }
        
        return area;
    }
};