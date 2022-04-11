struct Compare {
    bool operator()(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
};

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        priority_queue<vector<int>, vector<vector<int>>, Compare> q;
        
        for(auto b : boxTypes)
            q.push(b);
        
        int count = 0;
        while(!q.empty()) {
            int n = min(q.top()[0], truckSize);
            count += n * q.top()[1];
            q.pop();
            truckSize -= n;
            if(truckSize == 0)
                break;
        }
        return count;
    }
};