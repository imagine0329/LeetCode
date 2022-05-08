class Solution {
public:
    bool canTransform(string start, string end) {
        int n = start.length();
        int p1 = 0, p2 = 0;
        int xCount = 0;
        for(int i = 0; i < n; i++) {
            if(start[i] == 'X')
                xCount++;
            if(end[i] == 'X')
                xCount--;
        }
        
        if(xCount != 0)
            return false;
        
        while(p1 < n && p2 < n) {
            while(p1 < n && start[p1] == 'X')
                p1++;
                
            while(p2 < n && end[p2] == 'X')
                p2++;
                
            if(p1 == n && p2 == n)
                return true;
            if(p1 == n || p2 == n)
                return false;
            
            if(start[p1] != end[p2])
                return false;
            
            if(start[p1] == 'L' && p1 < p2)
                return false;
            if(start[p1] == 'R' && p1 > p2)
                return false;
            p1++; p2++;
        }
        return xCount == 0;
    }
};

/*
start = "RXXLRXRXL", end = "XRLXXRRLX"

XL -> LX        LXXX    XLXX
                i        j      i < j : false

RX -> XR        XRXX    RXXX
                 i      j       i > j : false

R's & L's 
diff : false
*/