class Solution {
public:
    int countPrimes(int n) {
        int bound = sqrt(n);
        vector<bool> nums(n, false);
        
        for(int i = 2; i <= bound; i++) {
            for(int j = i * i; j < n; j += i)
                nums[j] = true;
        }
        
        int primes = 0;
        for(int i = 2; i < n; i++)
            primes += nums[i] ? 0 : 1;
        
        return primes;
    }
};