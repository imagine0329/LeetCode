class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int two = cost[0], one = cost[1];
        
        for(int i = 2; i < cost.size(); i++) {
            int temp = min(one, two) + cost[i];
            two = one;
            one = temp;
        }
        
        return min(one, two);
    }
};