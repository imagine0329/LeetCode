class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int available = 0;
        for(int i = 0; i < flowerbed.size(); i++) {
            if(flowerbed[i] == 0) {
                bool left = (i == 0) || flowerbed[i - 1] == 0;
                bool right = (i == flowerbed.size() - 1) || flowerbed[i + 1] == 0;
                if(left && right) {
                    flowerbed[i] = 1;
                    available++;
                    if(available >= n)
                        return true;
                }
            }
        }
        
        return available >= n;
    }
};