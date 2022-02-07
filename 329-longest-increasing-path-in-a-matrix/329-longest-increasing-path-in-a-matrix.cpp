class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> offset = {-1, 0, 1, 0, -1};
        vector<vector<int>> outdegree(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                for(int i = 0; i < 4; i++) {
                    int r = row + offset[i], c = col + offset[i + 1];
                    if(r >= 0 && r < m && c >= 0 && c < n && matrix[row][col] < matrix[r][c])
                        outdegree[row][col]++;
                }
            }
        }
        
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(outdegree[row][col] == 0)
                    q.push({row, col});
            }
        }
        
        int longest = 0;
        while(!q.empty()) {
            longest++;
            int sz = q.size();
            while(sz--) {
                int row = q.front().first, col = q.front().second;
                q.pop();
                for(int i = 0; i < 4; i++) {
                    int r = row + offset[i], c = col + offset[i + 1];
                    if(r >= 0 && r < m && c >= 0 && c < n && matrix[row][col] > matrix[r][c]) {
                        if(--outdegree[r][c] == 0)
                            q.push({r, c});
                    }
                }
            }
        }
        
        return longest;
    }
};