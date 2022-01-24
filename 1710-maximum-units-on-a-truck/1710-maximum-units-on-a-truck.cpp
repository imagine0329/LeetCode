class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        priority_queue<vector<int>, vector<vector<int>>, Comparator> q;
        for(auto b : boxTypes)
            q.push(b);
        
        int sum = 0;
        while(!q.empty()) {
            int num = min(q.top().front(), truckSize);
            sum += num * q.top().back();
            q.pop();
            truckSize -= num;
            if(truckSize == 0)
                break;
        }
        
        return sum;
    }
    
    struct Comparator {
        bool operator()(vector<int> const& a, vector<int> const& b) {
            return a[1] < b[1];
        }
    };
};