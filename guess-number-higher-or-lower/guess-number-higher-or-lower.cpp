/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        /*  binary search
        int left = 1, right = n, pivot;
        while(left <= right)
        {
            pivot = left + (right - left)/2;
            int num = guess(pivot);
            if(num == 0)
                return pivot;
            else if(num == 1)
                left = pivot + 1;
            else
                right = pivot - 1;
        }*/
        
        /*  ternary search*/
        int low = 1, high = n;
        while(low <= high)
        {
            int mid1 = low + (high - low)/3;
            int mid2 = high - (high - low)/3;
            int res1 = guess(mid1);
            int res2 = guess(mid2);
            if(res1 == 0)
                return mid1;
            if(res2 == 0)
                return mid2;
            
            if(res1 < 0)
                high = mid1 - 1;
            else if(res2 > 0)
                low = mid2 + 1;
            else
            {
                low = mid1 + 1;
                high = mid2 + 1;
            }
        }
        
        return -1;
    }
};