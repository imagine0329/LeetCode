class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> result;
        
        while(n != 1 && result.find(n) == result.end()) {
            result.insert(n);
            int sum = getNext(n);
            n = sum;
        }
        
        return n == 1;
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