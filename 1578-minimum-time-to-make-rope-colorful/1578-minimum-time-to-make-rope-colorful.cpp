class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = neededTime[0], max_cost = neededTime[0];
        
        for(int i = 1; i < neededTime.size(); i++) {
            if(colors[i] != colors[i - 1]) {
                ans -= max_cost;
                max_cost = 0;
            }
            
            ans += neededTime[i];
            max_cost = max(max_cost, neededTime[i]);
        }
        
        return ans - max_cost;
    }
};