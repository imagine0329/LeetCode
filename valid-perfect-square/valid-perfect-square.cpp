class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num < 2)
            return true;
        
        /*  Using Newton's Method*/
        long x = num / 2;
        while(x*x > num)
        {
            x = (x + (num/x)) / 2;
        }
        
        return (x*x == num);
        
        
        /*  Using Binary Search
        long left = 2, right = num/2;
        while(left <= right)
        {
            long mid = left + (right-left)/2;
            long squared = mid*mid;
            if(squared == num)
                return true;
            if(squared > num)
                right = mid - 1;
            else
                left = mid + 1;
        }
        
        return false;
        */
    }
};