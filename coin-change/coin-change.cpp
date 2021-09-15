class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> solution(amount + 1, amount + 1);
        solution[0] = 0;
        
        for(int c : coins)
        {
            for(int i=c; i<amount+1; i++)
                solution[i] = min(solution[i-c]+1, solution[i]);
        }
        
        return solution.back() > amount ? -1 : solution.back();
    }
};