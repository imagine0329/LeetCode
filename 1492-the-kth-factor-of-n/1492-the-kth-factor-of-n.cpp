class Solution {
public:
    int kthFactor(int n, int k) {
        int sq = sqrt(n);
        vector<int> v;
        
        for(int i = 1; i <= sq; i++) {
            if(n % i == 0) {
                v.push_back(i);
                if(--k == 0)
                    return i;
            }
        }
        
        if(sq * sq == n)
            k++;
        
        int sz = v.size();
        return k <= sz ? n / v[sz - k] : -1;
    }
};