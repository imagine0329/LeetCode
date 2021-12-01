class Leaderboard {
private:
    unordered_map<int, int> m;
    
public:
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        m[playerId] += score;
    }
    
    int top(int K) {
        vector<int> scores;
        for(auto id : m)
            scores.push_back(id.second);
        
        sort(scores.begin(), scores.end(), 
             [](int& a, int& b){
                return a > b;
        });
        
        int sum = 0;
        for(int i=0; i<K; i++)
            sum += scores[i];
        
        return sum;
    }
    
    void reset(int playerId) {
        m[playerId] = 0;
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */