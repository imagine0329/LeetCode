class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2)
            return 0;
        
        vector<bool> v(n, false);
        for(int i=2; i<=sqrt(n); i++)
        {
            if(v[i])
                continue;
            
            for(int j=i*i; j<n; j+=i)
                v[j] = true;
        }
        
        int count = 0;
        for(int i=2; i<n; i++)
        {
            if(!v[i])
                count++;
        }
        
        return count;
    }
};