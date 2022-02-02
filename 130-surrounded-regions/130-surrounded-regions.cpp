class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        queue<pair<int, int>> q;
        
        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O')
                q.push({i, 0});
            if(board[i][n-1] == 'O')
                q.push({i, n-1});
        }
        
        for(int i = 0; i < n; i++) {
            if(board[0][i] == 'O')
                q.push({0, i});
            if(board[m-1][i] == 'O')
                q.push({m-1, i});
        }
        
        bfs(board, q);
        
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(board[row][col] == '#')
                    board[row][col] = 'O';
                else if(board[row][col] == 'O')
                    board[row][col] = 'X';
            }
        }
    }
    
    void bfs(vector<vector<char>>& board, queue<pair<int, int>>& q) {
        int m = board.size(), n = board[0].size();
        
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int r = q.front().first, c = q.front().second;
                q.pop();
                board[r][c] = '#';
                
                vector<int> offset = {-1, 0, 1, 0, -1};
                for(int i = 0; i < 4; i++) {
                    int row = r + offset[i], col = c + offset[i + 1];
                    if(row >= 0 && row < m && col >= 0 && col < n && board[row][col] == 'O')
                        q.push({row, col});
                }
            }
        }
    }
};