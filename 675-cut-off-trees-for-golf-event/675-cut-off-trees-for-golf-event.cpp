class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {        
        int m = forest.size(), n = forest[0].size();
        vector<vector<int>> trees;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(forest[i][j] > 1)
                    trees.push_back({forest[i][j], i, j});
            }
        }
        
        sort(trees.begin(), trees.end());
        
        int ans = 0;
        for(int i = 0, cur_row = 0, cur_col = 0; i < trees.size(); i++) {
            int step = bfs(forest, cur_row, cur_col, trees[i][1], trees[i][2]);
            if(step == -1)
                return -1;
            ans += step;
            cur_row = trees[i][1];
            cur_col = trees[i][2];
        }
        
        return ans;
    }
    
    int bfs(vector<vector<int>>& forest, int row, int col, int target_row, int target_col) {
        if(row == target_row && col == target_col)
            return 0;
        
        vector<vector<bool>> visited(forest.size(), vector<bool>(forest[0].size(), false));
        queue<pair<int, int>> q;
        vector<int> dir = {-1, 0, 1, 0, -1};
        int step = 0;
        
        visited[row][col] = true;
        q.push({row, col});
        while(!q.empty()) {
            step++;
            int n = q.size();
            while(n--) {
                int cur_row = q.front().first, cur_col = q.front().second;
                q.pop();
                for(int i = 0; i < 4; i++) {
                    int r = cur_row + dir[i], c = cur_col + dir[i+1];
                    if(r < 0 || r >= forest.size() || c < 0 || c >= forest[0].size()
                        || visited[r][c] || forest[r][c] == 0)
                        continue;
                    if(r == target_row && c == target_col)
                        return step;
                    
                    visited[r][c] = true;
                    q.push({r, c});
                }
            }
        }
        
        return -1;
    }
    
};