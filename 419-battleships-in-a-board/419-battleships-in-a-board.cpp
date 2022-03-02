class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        
        
        int count = 0;
        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                if(!visited[r][c] && board[r][c] == 'X') {
                    count++;
                    bfs(board, visited, r, c);
                }
            }
        }
        return count;
    }
    
    void bfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int row, int col) {
        int m = board.size(), n = board[0].size();
        queue<pair<int, int>> q;
        vector<int> offset = {-1, 0, 1, 0, -1};
        
        q.push({row, col});
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                row = q.front().first;
                col = q.front().second;
                q.pop();
                visited[row][col] = true;
                
                for(int i = 0; i < 4; i++) {
                    int r = row + offset[i], c = col + offset[i + 1];
                    if(r >= 0 && r < m && c >= 0 && c < n && !visited[r][c] && board[r][c] == 'X') {
                        q.push({r, c});
                        visited[r][c] = true;
                    }
                }
            }
        }
    }
};