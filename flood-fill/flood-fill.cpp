class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(newColor == image[sr][sc])
            return image;
        
        fill(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }
    
    void fill(vector<vector<int>>& image, int sr, int sc, int newColor, int oldColor)
    {
        if(sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size())
            return;
        
        if(image[sr][sc] != oldColor)
            return;
        
        image[sr][sc] = newColor;
        
        int rowOffset[4] = {-1, 0, 1, 0};
        int colOffset[4] = {0, 1, 0, -1};
        
        for(int i=0; i<4; i++)
            fill(image, sr + rowOffset[i], sc + colOffset[i], newColor, oldColor);
    }
};