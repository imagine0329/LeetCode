class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int front = 0, rear = 0;
        
        for(int i = 0; i < k; i++)
            front += cardPoints[i];
        
        int maxPoint = front;
        for(int i = k - 1; i >= 0; i--) {
            front -= cardPoints[i];
            rear += cardPoints[n - (k - i)];
            maxPoint = max(maxPoint, front + rear);
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
    
    [1, 2, 3, 4, 5, 6, 1]
           i           n - k - i
    front = 6
    rear = 12
    */