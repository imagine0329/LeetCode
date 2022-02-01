class Solution {
public:
    int kthFactor(int n, int k) {
        int m = sqrt(n);
        vector<int> factors;
        
        for(int i = 1; i <= m; i++) {
            if(n % i == 0) {
                factors.push_back(i);
                if(i * i != n)
                    factors.push_back(n / i);
            }
        }
        
        sort(factors.begin(), factors.end());
        return factors.size() < k ? -1 : factors[k - 1];
    }
};