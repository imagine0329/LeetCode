class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> result;
        
        while(n != 1) {
            int sum = getNext(n);
            if(result.find(sum) != result.end())
                return false;
            
            result.insert(sum);
            n = sum;
        }
        
        return true;
    }
    
    int getNext(int n) {
        int x = n;
        int sum = 0;
        while(x > 0) {
            int r = x % 10;
            sum += r * r;
            x /= 10;
        }
        return sum;
    }
};