class Solution {
public:
    int maxA(int n) {
        int maximum = n;
        for(int i = 1; i < n - 2; i++) {
            maximum = max(maximum, maxA(i) * (n - i - 1));
        }
        
        return maximum;
        
    }
};