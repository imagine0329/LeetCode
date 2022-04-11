struct Compare {
    bool operator()(vector<int>& a, vector<int>& b) {
        return a[1] > b[1];
    }
};

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), Compare());
        int count = 0;
        for(auto box : boxTypes) {
            int n = min(box[0], truckSize);
            count += (n * box[1]);
            truckSize -= n;
            if(truckSize == 0)
                break;
        }
        return count;
    }
};