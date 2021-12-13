class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> rows[9], cols[9], boxes[9];
        
        for(int r=0; r<board.size(); r++)
        {
            for(int c=0; c<board.front().size(); c++)
            {
                int curr = board[r][c];
                if(curr == '.')
                    continue;
                
                if(rows[r].find(curr) != rows[r].end())
                    return false;
                rows[r].insert(curr);
                
                if(cols[c].find(curr) != cols[c].end())
                    return false;
                cols[c].insert(curr);
                
                int idx = (r/3)*3 + (c/3);
                if(boxes[idx].find(curr) != boxes[idx].end())
                    return false;
                boxes[idx].insert(curr);
            }
        }
        
        return true;
    }
    
};