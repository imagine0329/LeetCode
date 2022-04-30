class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        int minimum = INT_MAX;
        sort(timePoints.begin(), timePoints.end());
        int diff;
        for(int i = 1; i < n; i++) {
            diff = getDiff(timePoints[i - 1], timePoints[i]);
            minimum = min(minimum, min(diff, 1440 - diff));
        }
        
        diff = getDiff(timePoints[0], timePoints[n - 1]);
        minimum = min(minimum, min(diff, 1440 - diff));
        return minimum;
    }
    
    int getDiff(string t1, string t2) {
        int h1 = stoi(t1.substr(0, 2));
        int m1 = stoi(t1.substr(3, 2));
        int h2 = stoi(t2.substr(0, 2));
        int m2 = stoi(t2.substr(3, 2));
        
        return abs((h2 - h1) * 60 + (m2 - m1));
    }
};
    
/*
["00:00","23:59","00:00"]
sort -> ["00:00","00:00", "23:59"]
HH = 00 ~ 24
MM = 00 ~ 60

 t1                                t2
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23
    --------------1st--------------40-------------2nd--------
--20

ans = minimum(1st, 2nd)

1st = t1 to t2 = t2 - t1
2nd = t2 to t1 = t1 + (1440 - t2)

t1 = 80     t2 = 940*/