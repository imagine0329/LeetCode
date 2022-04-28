class Logger {
private:
    queue<pair<string, int>> q;
    unordered_set<string> s;
    
public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        while(!q.empty()) {
            if(q.front().second + 10 <= timestamp) {
                s.erase(q.front().first);
                q.pop();
            }
            else
                break;
        }
        
        if(s.find(message) == s.end()) {
            q.push({message, timestamp});
            s.insert(message);
            return true;
        }
        else
            return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
