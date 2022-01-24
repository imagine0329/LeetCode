class Leaderboard {
private:
    unordered_map<int, int> scores;
    set<pair<int, int>, greater<pair<int, int>>> sortedScores;
    
public:
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        sortedScores.erase({scores[playerId], playerId});
        scores[playerId] += score;
        sortedScores.insert({scores[playerId], playerId});
    }
    
    int top(int K) {
        int sum = 0;
        for(auto score : sortedScores) {
            sum += score.first;
            if(--K == 0)
                break;
        }
        
        return sum;
    }
    
    void reset(int playerId) {
        sortedScores.erase({scores[playerId], playerId});
        scores[playerId] = 0;
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */