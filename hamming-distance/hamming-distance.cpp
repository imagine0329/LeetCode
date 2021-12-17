class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        
        while(x != 0 || y != 0)
        {
            int x_temp = x & 1;
            int y_temp = y & 1;
            if(x_temp != y_temp)
                count++;
            
            x >>= 1;
            y >>= 1;
        }
        
        return count;
    }
};