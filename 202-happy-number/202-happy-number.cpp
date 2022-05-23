class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> result;
        
        while(n != 1) {
            int x = n;
            int sum = 0;
            while(x > 0) {
                int r = x % 10;
                sum += r * r;
                x /= 10;
            }
            
            if(result.find(sum) != result.end())
                return false;
            
            result.insert(sum);
            n = sum;
        }
        
        return true;
    }
};