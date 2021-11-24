class Logger {
private:
    map<string, int> m;
    
public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(m.find(message) == m.end())
        {
            m[message] = timestamp;
            return true;
        }
        
        if(timestamp - m[message] < 10)
            return false;
        else
        {
            m[message] = timestamp;
            return true;
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */