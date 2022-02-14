class Solution {
public:
    bool isPerfectSquare(int num) {
        long long left = 0, right = num / 2 + 1;
        long long mid;
        while(left < right) {
            mid = left + (right - left) / 2;
            if(mid * mid < num)
                left = mid + 1;
            else
                right = mid;
        }
        
        return left * left == num;
    }
};