class Solution {
public:
    bool isHappy(int n) {
        
        int sum = n;
        unordered_set<int> s;
        
        while(sum != 1)
        {
            if(s.find(sum) != s.end())
                return false;
            
            s.insert(sum);
            sum = 0;
            while(n != 0)
            {
                int x = n % 10;
                n = n / 10;
                sum += x*x;
            }
            
            n = sum;
        }
        
        if(sum == 1)
            return true;
        else
            return false;
    }
};