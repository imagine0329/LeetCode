class DetectSquares {
private:
    vector<vector<int>> cntPoints;
    vector<pair<int, int>> points;
    
public:
    DetectSquares() {
        cntPoints = vector<vector<int>>(1001, vector<int>(1001, 0));
    }
    
    void add(vector<int> point) {
        cntPoints[point[0]][point[1]]++;
        points.push_back({point[0], point[1]});
    }
    
    int count(vector<int> point) {
        int x1 = point[0], y1 = point[1];
        int count = 0;
        for(auto p : points) {
            int x3 = p.first, y3 = p.second;
            if(x1 == x3 || y1 == y3 || abs(x1 - x3) != abs(y1 - y3))
                continue;
            
            count += cntPoints[x1][y3] * cntPoints[x3][y1];
        }
        return count;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */

/*
  (x', y')    (x, y')
    3           2
    
    1           p
  (x', y)     (x, y)
   
p = (x, y)
points w/ same x    = p2 = (x, y')
points w/ same y    = p1 = (x', y)                            
last point = (x', y')
                            

key(x)     val(y)
x           {y'}
x'          {y, y'}
    
diagonal point = (x', y')
x'          {y, y'}     y = p's y
x           {y'}        y' = dp's y
*/