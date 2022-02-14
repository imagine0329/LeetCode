class Solution {
public:
    bool isPerfectSquare(int num) {
        int n = num / 2 + 1;
        for(long long i = 1; i <= n; i++) {
            if(i * i == num) return true;
        }
        return false;
    }
};