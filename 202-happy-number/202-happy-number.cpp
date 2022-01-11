class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        
        int x = n, res = n;
        
        while(res != 1)
        {
            x = res;
            res = 0;
            while(x)
            {
                res += pow(x % 10, 2);
                x /= 10;
            }
            
            if(seen.find(res) != seen.end())
                return false;
            
            seen.insert(res);
        }
        
        return true;
    }
};