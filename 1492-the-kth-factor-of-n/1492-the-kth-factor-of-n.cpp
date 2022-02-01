class Solution {
public:
    int kthFactor(int n, int k) {
        int m = sqrt(n);
        vector<int> factors;
        
        for(int i = 1; i <= m; i++) {
            if(n % i == 0) {
                factors.push_back(i);
                --k;
                if(k == 0)
                    return i;
            }
        }
        
        if(m * m == n)
            k++;
        
        return factors.size() < k ? -1 : n / factors[factors.size() - k];
    }
};