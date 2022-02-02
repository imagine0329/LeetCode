class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ans = 0;
        int total_tank = 0, tank = 0;
        
        for(int i = 0; i < gas.size(); i++) {
            if(tank + gas[i] < cost[i]) {
                ans = (i + 1) % gas.size();
                tank = 0;
            }
            else
                tank += gas[i] - cost[i];
            
            total_tank += gas[i] - cost[i];
        }
        
        return total_tank >= 0 ? ans : -1;
    }
};