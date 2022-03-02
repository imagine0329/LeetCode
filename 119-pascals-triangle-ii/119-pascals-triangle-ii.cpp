class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev, curr;
        curr.push_back(1);
        for(int i = 0; i < rowIndex; i++) {
            for(int j = 1; j <= i + 1; j++) {
                if(j == i + 1)
                    curr.push_back(1);
                else
                    curr[j] = prev[j - 1] + prev[j];
            }
            prev = curr;
        }
        
        return curr;
    }
};