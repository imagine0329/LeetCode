class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        int minimum = INT_MAX;
        sort(timePoints.begin(), timePoints.end());
        
        for(int i = 1; i < n + 1; i++) {
            int t1_HH, t1_MM, t2_HH, t2_MM;
            if(i == n) {
                t1_HH = stoi(timePoints[0].substr(0, 2));
                t1_MM = stoi(timePoints[0].substr(3, 2));
                t2_HH = stoi(timePoints[n - 1].substr(0, 2));
                t2_MM = stoi(timePoints[n - 1].substr(3, 2));
            }
            else {
                t1_HH = stoi(timePoints[i - 1].substr(0, 2));
                t1_MM = stoi(timePoints[i - 1].substr(3, 2));
                t2_HH = stoi(timePoints[i].substr(0, 2));
                t2_MM = stoi(timePoints[i].substr(3, 2));
            }
            
            int t1 = t1_HH * 60 + t1_MM, t2 = t2_HH * 60 + t2_MM;
            int firstGap = t2 - t1;
            int secondGap = t1 + (1440 - t2);
            minimum = min(minimum, min(firstGap, secondGap));
        }
        return minimum;
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