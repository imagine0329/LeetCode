class Solution {
public:
    int countArrangement(int n) {
        vector<bool> visited(n, 0);
        int count = 0;
        
        backtracking(n, visited, count, 1);
        
        return count;
    }
    
    void backtracking(int n, vector<bool>& visited, int& count, int i) {
        if(i > n) {
            count++;
            return;
        }
        
        for(int k = 1; k <= n; k++) {
            if(visited[k-1])
                continue;
            
            if(k % i == 0 || i % k == 0) {
                visited[k-1] = true;
                backtracking(n, visited, count, i + 1);
                visited[k-1] = false;
            }
        }
    }
};