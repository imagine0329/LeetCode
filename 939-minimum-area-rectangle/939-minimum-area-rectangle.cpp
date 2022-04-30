class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> m;
        int res = INT_MAX;
        
        for(auto point : points)
            m[point[0]].insert(point[1]);
        
        for(int i = 0; i < points.size() - 1; i++) {
            for(int j = i + 1; j < points.size(); j++) {
                if(points[i][0] == points[j][0] || points[i][1] == points[j][1])
                    continue;
                
                if(m[points[i][0]].count(points[j][1]) && m[points[j][0]].count(points[i][1]))
                    res = min(res, abs(points[i][0] - points[j][0]) * abs(points[i][1] - points[j][1]));
            }
        }
        
        return res == INT_MAX ? 0 : res;
    }
};

/*
[x, y]
points = [[0,1],[1,3],[3,3],[4,4],[1,4],[2,3],[1,0],[3,4]]

key     val
x       y
0       {1}
1       {3, 4, 0}
3       {3, 4}
4       {4}
2       {3}

x1 == x2
y1 == y2

y2  o       o
    
y1  o   o   o
    x1  x2  x3
    
*/
    