class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> times;
        int totalTime = 24 * 60;
        
        for(auto point : timePoints) {
            int hour = stoi(point.substr(0, 2)) * 60;
            int minute = stoi(point.substr(3, 2));
            times.push_back(hour + minute);
        }
        
        sort(times.begin(), times.end());
        
        int minDiff = INT_MAX;
        for(int i = 1; i < times.size(); i++) {
            int diff1 = times[i] - times[i - 1];
            int diff2 = totalTime - times[i] + times[i - 1];
            minDiff = min(minDiff, min(diff1, diff2));
        }
        
        minDiff = min(minDiff, totalTime - times[times.size() - 1] + times[0]);
        return minDiff;
    }
};


/*
hour    0   1   2   3   4   5   6 ...
min         20              40
            a               b
            |<------------->|       x
        --->|               |<---   y
        
        x = b - a
        y = totalTime - b + a
            */