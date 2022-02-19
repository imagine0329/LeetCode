class UndergroundSystem {
private:
    unordered_map<string, unordered_map<string, pair<int, int>>> history;
    unordered_map<int, pair<string, int>> customer;
    
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        customer[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        int time = t - customer[id].second;
    
        history[customer[id].first][stationName].first += time;
        history[customer[id].first][stationName].second++;
        
        customer.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        int time = history[startStation][endStation].first;
        int divisor = history[startStation][endStation].second;
        
        return (double) time / divisor;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */