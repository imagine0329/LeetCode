class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> visited(n * n + 1, false);
        queue<pair<int, int>> q;
        
        q.push({1, 0});
        visited[1] = true;
        
        while(!q.empty()) {
            int p = q.front().first, step = q.front().second;
            q.pop();
            if(p == n * n) 
                return step;
            
            for(int i = 1; i <= 6 && p + i <= n * n; i++) {
                int val = getBoardValue(board, p + i);
                int next = val == -1 ? p + i : val;
                if(!visited[next]) {
                    visited[next] = true;
                    q.push({next, step + 1});
                }
            }
        }
        return -1;
    }
    
    int getBoardValue(vector<vector<int>>& board, int p) {
        int n = board.size();
        int c = (p - 1) % n;
        int r = n - ((p - 1) / n) - 1;
        
        if(((n % 2 == 0) && (r % 2 == 0)) || ((n % 2 == 1) && (r % 2 == 1)))
            c = n - c - 1;
        return board[r][c];
    }
};