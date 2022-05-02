class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int point = 0;
        int maxPoint;
        int i = 0, j = k - 1;
        
        for(int i = 0; i < k; i++)
            point += cardPoints[i];
        
        maxPoint = point;
        while(k--) {
            i = i == 0 ? cardPoints.size() - 1 : i - 1;
            
            point -= cardPoints[j--];
            point += cardPoints[i];
            
            maxPoint = max(maxPoint, point);
        }
        return maxPoint;
    }
};

/*
cardPoints = [1,2,3,4,5,6,1], k = 3
    
    [1, 2, 3, 4, 5, 6, 1]
    [1]               [1]   k = 2
                   [6, 1]
    [1, 2]
    
    k = 3    
     i     j
    [1, 2, 3]   = sum
    i--
    sum -= arr[j]
    sum += arr[i]
    j--     until j == arr.size - 1
        j              i
    [1, 2]            [1]
     j              i
    [1]            [6, 1]
                 i     j
    []          [5, 6, 1]
    

    [9,7,7,9,7,7,9]     k = 7
    */
