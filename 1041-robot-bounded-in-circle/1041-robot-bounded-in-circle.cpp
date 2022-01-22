class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, faceTo = 0;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        for(auto c : instructions) {
            if(c == 'L')
                faceTo = (faceTo + 3) % 4;
            else if(c == 'R')
                faceTo = (faceTo + 1) % 4;
            else {
                x += directions[faceTo][0];
                y += directions[faceTo][1];
            }
        }
        
        return (x == 0 && y == 0) || (faceTo != 0);
    }
};