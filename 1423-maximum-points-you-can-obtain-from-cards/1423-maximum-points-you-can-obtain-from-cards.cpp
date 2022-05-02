class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int maxPoint = 0;
        
        vector<int> front(k + 1, 0), rear(k + 1, 0);
        
        for(int i = 1; i <= k; i++) {
            front[i] = front[i - 1] + cardPoints[i - 1];
            rear[i] = rear[i - 1] + cardPoints[n - i];
        }
        
        for(int i = 0; i <= k; i++) {
            int sum = front[i] + rear[k - i];
            maxPoint = max(maxPoint, sum);
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
    
     0  1  2  3
    [0, 1, 3, 6]    
    [0, 1, 7, 12]   
    
    i = 0   0
    j = 3   12

    i = 1   1
    j = 2   7
    
    i = 2   3
    j = 1   1
*/