class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if(oldColor == newColor)
            return image;
        
        vector<int> offset = {-1, 0, 1, 0, -1};
        queue<pair<int, int>> q;
        q.push({sr, sc});
        
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                sr = q.front().first;
                sc = q.front().second;
                q.pop();
                
                image[sr][sc] = newColor;
                
                for(int i = 0; i < 4; i++) {
                    int r = sr + offset[i], c = sc + offset[i+1];
                    if(r < 0 || r >= image.size() || c < 0 || c >= image[0].size())
                        continue;
                    if(image[r][c] == oldColor)
                        q.push({r, c});
                }
            }
        }
        
        
        return image;
    }
};