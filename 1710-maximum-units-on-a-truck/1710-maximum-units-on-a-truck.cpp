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
        
        int sum = 0;
        while(!q.empty()) {
            auto b = q.top(); q.pop();
            int n = min(truckSize, b[0]);
            sum += n * b[1];
            truckSize -= n;
            if(truckSize == 0) break;
        }
        
        return sum;
    }
};