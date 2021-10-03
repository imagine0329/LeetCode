class Solution {
public:
    int hammingWeight(int n)
    {
        int count = 0;
        while(n)
        {
            count++;
            n &= n-1;
        }
        
        return count;
    }
    
    vector<int> countBits(int n) {
        vector<int> ans;
        
        for(int i=0; i<n+1; i++)
        {
            ans.push_back(hammingWeight(i));
        }
        
        return ans;
    }
};