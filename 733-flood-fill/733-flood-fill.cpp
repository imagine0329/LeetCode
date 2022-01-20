class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
    
    void dfs(vector<vector<int>>& image, int sr, int sc, int oldColor, int newColor) {
        vector<int> offset = {-1, 0, 1, 0, -1};
        
        image[sr][sc] = '#';
        for(int i = 0; i < 4; i++) {
            int r = sr + offset[i], c = sc + offset[i+1];
            if(r < 0 || r >= image.size() || c < 0 || c >= image[0].size())
                continue;
            if(image[r][c] == oldColor)
                dfs(image, r, c, oldColor, newColor);
        }
        
        image[sr][sc] = newColor;
    }
};