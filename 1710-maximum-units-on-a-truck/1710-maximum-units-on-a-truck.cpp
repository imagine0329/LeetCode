class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] > b[1];
        });
        
        int sum = 0;
        for(auto b : boxTypes) {
            int num = min(b[0], truckSize);
            sum += num * b[1];
            truckSize -= num;
            if(truckSize == 0)
                break;
        }
        
        return sum;
    }
};