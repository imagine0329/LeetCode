class Leaderboard {
private:
    unordered_map<int, int> board;
    
public:
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        board[playerId] += score;
    }
    
    int top(int K) {
        priority_queue<int, vector<int>, greater<int>> q;
        for(auto s : board) {
            q.push(s.second);
            if(q.size() > K)
                q.pop();
        }
        
        int sum = 0;
        while(!q.empty()){
            sum += q.top();
            q.pop();
        }
        
        return sum;
    }
    
    void reset(int playerId) {
        board[playerId] = 0;
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */