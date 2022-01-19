class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sz = flowerbed.size();
        int count = 0;
        
        for(int i = 0; i < sz; i++) {
            if(flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && (i == sz-1 || flowerbed[i+1] == 0)) {
                flowerbed[i] = 1;
                count++;
            }
        }
        
        return count >= n;
    }
};