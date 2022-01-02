class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        if(forest.empty() || forest[0].empty()) 
            return 0;
        
        int m = forest.size(), n = forest[0].size();
        
        vector<vector<int>> trees;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(forest[i][j] > 1)
                    trees.push_back({forest[i][j], i, j});
            }
        }
        
        sort(trees.begin(), trees.end());
        
        int ans = 0;
        
        for(int i=0, cur_row = 0, cur_col = 0; i<trees.size(); i++)
        {
            int step = next_step(forest, cur_row, cur_col, trees[i][1], trees[i][2]);
            if(step == -1)
                return -1;
            ans += step;
            cur_row = trees[i][1];
            cur_col = trees[i][2];
        }
        
        return ans;
    }
    
private:
    int next_step(vector<vector<int>>& forest, int sr, int sc, int er, int ec)
    {
        if(sr == er && sc == ec)
            return 0;
        
        int m = forest.size(), n = forest[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<int> dir = {-1, 0, 1, 0, -1};
        int step = 0;
        
        visited[sr][sc] = true;
        q.push({sr, sc});
        
        while(!q.empty())
        {
            step++;
            int q_size = q.size();
            for(int i=0; i<q_size; i++)
            {
                int row = q.front().first, col = q.front().second;
                q.pop();
                for(int k=0; k<4; k++)
                {
                    int r = row + dir[k], c = col + dir[k+1];
                    if(r < 0 || r >= m || c < 0 || c >= n || visited[r][c] == 1 || forest[r][c] == 0)
                        continue;
                    if(r == er && c == ec)
                        return step;
                    visited[r][c] = true;
                    q.push({r, c});
                }
            }
        }
        
        return -1;
        
    }
};