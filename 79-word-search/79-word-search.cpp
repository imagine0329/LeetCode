class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int row = 0; row < board.size(); row++) {
            for(int col = 0; col < board[0].size(); col++) {
                if(dfs(board, word, 0, row, col))
                    return true;
            }
        }
        
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string word, int idx, int row, int col) {
        if(idx == word.length()) return true;
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) return false;
        if(board[row][col] != word[idx]) return false;
        
        board[row][col] = '#';
        
        vector<int> offset = {-1, 0, 1, 0, -1};
        for(int i = 0; i < 4; i++) {
            if(dfs(board, word, idx + 1, row + offset[i], col + offset[i + 1])) return true;
        }
        
        board[row][col] = word[idx];
        return false;
    }
};