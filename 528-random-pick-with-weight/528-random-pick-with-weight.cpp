class Solution {
private:
    vector<int> accum;
    int size;
    
public:
    Solution(vector<int>& w) {            
        accum.push_back(w[0]);
        for(int i = 1; i < w.size(); i++)
            accum.push_back(accum[i - 1] + w[i]);
        size = accum.back();
    }
    
    int pickIndex() {
        int i = rand() % size;
        
        return upper_bound(accum.begin(), accum.end(), i) - accum.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
/*
 0  1  2
[1, 2, 2]

0:  1/5
1:  2/5
2:  2/5
    
01122
    
[1, 1]
50%
two numbers -> pick one number

[1, 1, 1, 1]
each prob = 25%
4 numbers -> pick 1

1%
1/100
1 ~ 20 = 0      20%
21 ~ 60 = 1     40%
61 ~ 100 = 2    40%

[20, 30, 50]
sum(w) = 100

[20, 50, 100]
random num = 30
30 > 20   -> index != 0
30 < 50   -> index = 1
*/