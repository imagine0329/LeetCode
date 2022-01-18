class Logger {
private:
    unordered_map<string, int> m;
    
public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(m.find(message) != m.end()) {
            if(timestamp < m[message] + 10)
                return false;
        }
            
        m[message] = timestamp;

        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */