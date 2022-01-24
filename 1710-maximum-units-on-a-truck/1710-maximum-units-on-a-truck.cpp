class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<int> buckets(1001, 0);
        int sum = 0;
        for(auto b : boxTypes)
            buckets[b[1]] += b[0];
                
        for(int i = 1000; i >= 0; i--) {
            if(buckets[i] == 0)
                continue;
            
            int box = min(truckSize, buckets[i]);
            sum += box * i;
            truckSize -= box;
            if(truckSize == 0) break;
        }
            
        return sum;
    }
};