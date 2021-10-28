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
        }
        
        return -1;
    }
};