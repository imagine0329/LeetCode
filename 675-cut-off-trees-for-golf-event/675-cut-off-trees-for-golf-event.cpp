typedef pair<int, pair<int, int>> element;

class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int m = forest.size(), n = forest[0].size();
        vector<vector<int>> trees;
        
        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                if(forest[r][c] > 1)
                    trees.push_back({forest[r][c], r, c});
            }
        }
        
        sort(trees.begin(), trees.end());
        
        int row = 0, col = 0;
        int ans = 0;
        for(int i = 0; i < trees.size(); i++) {
            int step = bfs(forest, row, col, trees[i][1], trees[i][2]);
            if(step == -1) return -1;
            ans += step;
            row = trees[i][1];
            col = trees[i][2];
        }
        return ans;
    }
    
    int bfs(vector<vector<int>>& forest, int row, int col, int target_r, int target_c) {
        if(row == target_r && col == target_c) return 0;
        int m = forest.size(), n = forest[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        vector<int> offset = {-1, 0, 1, 0, -1};
        
        q.push({row, col});
        visited[row][col] = true;
        int step = 0;
        
        while(!q.empty()) {
            step++;
            int sz = q.size();
            while(sz--) {
                row = q.front().first; col = q.front().second;
                q.pop();

                for(int i = 0; i < 4; i++) {
                    int r = row + offset[i], c = col + offset[i + 1];
                    if(r >= 0 && r < m && c >= 0 && c < n && !visited[r][c] && forest[r][c] != 0) {
                        if(r == target_r && c == target_c) return step;
                        visited[r][c] = true;
                        q.push({r, c});
                    }
                }
            }
            
        }
        
        return -1;
    }
};