class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size(), n = image[0].size();
        int oldColor = image[sr][sc];
        if(oldColor == newColor) return image;
        
        vector<int> offset = {-1, 0, 1, 0, -1};
        queue<pair<int, int>> q;
        
        q.push({sr, sc});
        image[sr][sc] = newColor;
        
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int row = q.front().first, col = q.front().second;
                q.pop();
                
                for(int i = 0; i < 4; i++) {
                    int r = row + offset[i], c = col + offset[i + 1];
                    if(r >= 0 && r < m && c >= 0 && c < n && image[r][c] == oldColor) {
                        image[r][c] = newColor;
                        q.push({r, c});
                    }
                }
            }
        }
        
        return image;
    }
};