class Solution {
public:
    int getNext(int n)
    {
        int ans = 0;
        while(n != 0){
            ans += pow(n % 10, 2);
            n /= 10;
        }
        
        return ans;
    }
    
    bool isHappy(int n) {
        int slow = n, fast = getNext(getNext(n));
        
        while(slow != fast)
        {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        
        return slow == 1;
    }
};