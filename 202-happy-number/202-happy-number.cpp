class Solution {
private:
    int getNext(int n)
    {
        int ret = 0;
        while(n)
        {
            int x = n % 10;
            n /= 10;
            ret += x * x;
        }
        
        return ret;
    }
    
public:
    bool isHappy(int n) {
        int slow = n, fast = getNext(getNext(n));
        
        while(fast != 1 && slow != fast)
        {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        
        return fast == 1;
    }
};