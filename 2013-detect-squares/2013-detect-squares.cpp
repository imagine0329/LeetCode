class DetectSquares {
private:
    unordered_map<int, unordered_map<int, int>> points;
    
public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        points[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int count = 0;
        for(auto p : points) {
            int x = p.first;
            if(x == point[0])
                continue;
            for(auto ys : p.second) {
                int c0 = 0, c1 = 0, c2 = 0;
                int y = ys.first;
                if(y == point[1] || abs(x - point[0]) != abs(y - point[1]))
                    continue;
                
                c0 = ys.second;
                if(points[point[0]].find(y) != points[point[0]].end())
                    c1 = points[point[0]][y];
                if(points[x].find(point[1]) != points[x].end())
                    c2 = points[x][point[1]];

                count += c0 * c1 * c2;
            }
            
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