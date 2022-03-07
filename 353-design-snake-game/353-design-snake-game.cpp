class SnakeGame {
private:
    map<pair<int, int>, bool> occupied;
    deque<pair<int, int>> snake;
    vector<vector<int>> food;
    int w, h, foodIdx;
    
public:
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        this->w = width;
        this->h = height;
        this->food = food;
        foodIdx = 0;
        snake.push_back({0, 0});
        occupied[{0, 0}] = true;
    }
    
    int move(string direction) {
        int row = snake.front().first, col = snake.front().second;
        
        if(direction == "U") row--;
        else if(direction == "D") row++;
        else if(direction == "L") col--;
        else if(direction == "R") col++;
        
        pair<int, int> head = {row, col};
        pair<int, int> tail = {snake.back().first, snake.back().second};
        if(row < 0 || row >= h || col < 0 || col >= w || (occupied.find(head) != occupied.end() && head != tail)) return -1;
        
        if(food.size() > foodIdx && head.first == food[foodIdx][0] && head.second == food[foodIdx][1])
            foodIdx++;
        else {
            snake.pop_back();
            occupied.erase(tail);
        }
        
        snake.push_front(head);
        occupied[head] = true;
        return snake.size() - 1;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */