class Logger {
private:
    unordered_map<string, int> log;
    
public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(log.find(message) == log.end() || log[message] + 10 <= timestamp) {
            log[message] = timestamp;
            return true;
        }
        
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */