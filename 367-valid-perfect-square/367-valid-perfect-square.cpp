class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1, right = num / 2;
        
        while(left < right) {
            long long mid = left + (right - left) / 2;
            if(mid * mid < num)
                left = mid + 1;
            else
                right = mid;
        }
        
        return (long long)left * left == num;
    }
};