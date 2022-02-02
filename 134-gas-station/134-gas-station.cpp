class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ans = 0;
        int total_gas = 0, total_cost = 0, tank = 0;
        
        for(int i = 0; i < gas.size(); i++) {
            if(tank + gas[i] < cost[i]) {
                ans = (i + 1) % gas.size();
                tank = 0;
            }
            else
                tank += gas[i] - cost[i];
            
            total_gas += gas[i];
            total_cost += cost[i];
        }
        
        return total_gas >= total_cost ? ans : -1;
    }
};