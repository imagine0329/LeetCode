class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ans = 0;
        int total_tank = 0, tank = 0;
        
        for(int i = 0; i < gas.size(); i++) {
            tank += gas[i] - cost[i];
            total_tank += gas[i] - cost[i];
            if(tank < 0) {
                ans = i + 1;
                tank = 0;
            }
        }
        
        return total_tank >= 0 ? ans : -1;
    }
};