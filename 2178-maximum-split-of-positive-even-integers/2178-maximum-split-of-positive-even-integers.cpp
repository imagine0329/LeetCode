class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum % 2)
            return {};
        
        vector<long long> ans;
        long long i = 2, sum = 0;
        
        while((sum + i) <= finalSum) {
            ans.push_back(i);
            sum += i;
            i += 2;
        }
        
        int sz = ans.size();
        ans[sz - 1] += (finalSum - sum);
        return ans;
    }
};
/*
finalSum = 28
    
2 + 26
2 + 4 + 22
2 + 4 + 6 + 16      O
2 + 4 + 6 + 8 + 8   X
2 + 4 + 6 + 10 + 6  X
            12 + 4  X
            14 + 2  X
            
2 + 4 + 22
        8 + 14      O
            10 + 4  X
            12 + 2  X
            
2 + 4 + 22
        10 + 12     O
             
2 + 4 + 22
        12 + 10     X
        
2 + 26
    6 + 20
        8 + 12      O
            10 + 2  X
            

i = 2 4 6 8 ...
j = i + 2, i + 4, ...
    
i = 2
j = 4
    i + j + (j+2) + (j+4) + .. (j+k)
    remain < j + k
        i <- i + 2
*/