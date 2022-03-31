struct Compare {
   bool operator()(vector<int>& a, vector<int>& b) {
       return a[1] > b[1];
   }
};

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), Compare());
        
        int sum = 0;
        for(auto b : boxTypes) {
            int n = min(truckSize, b[0]);
            sum += n * b[1];
            truckSize -= n;
            if(truckSize == 0)
                break;
        }
        
        return sum;
    }
};