class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0;
        
        int left_max = 0, right_max = 0;
        int left = 0, right = height.size() - 1;
        while(left < right) {
            if(height[left] <= height[right]) {
                if(left_max <= height[left])
                    left_max = height[left];
                else
                    water += left_max - height[left];
                left++;
            }
            else {
                if(right_max <= height[right])
                    right_max = height[right];
                else
                    water += right_max - height[right];
                right--;
            }
        }
        
        return water;
    }
};

/*
        left_max = 2
        right_max = 2
        h = min(l_max, r_max) - height[l]
        
height = [2,1,0,1,1,0,1,3,2,1,2,3]
          m     l             r m

           l                 r
        [5,1,0,1,1,0,1,3,2,1,6,3]
         m                   m
*/