class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int point = 0;
        for(int i = 0; i < k; i++)
            point += cardPoints[i];
        
        int maxPoint = point;
        int i = 0, j = k - 1;
        while(k--) {
            if(i == 0)
                i = cardPoints.size() - 1;
            else
                i--;
            
            point -= cardPoints[j];
            point += cardPoints[i];
            j--;
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
