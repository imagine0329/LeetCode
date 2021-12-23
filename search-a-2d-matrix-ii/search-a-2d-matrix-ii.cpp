class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0)
            return false;
        
        int n = min(matrix.size(), matrix[0].size());
        for(int i=0; i<n; i++)
        {
            int v = binarySearch(matrix, target, i, true);
            int h = binarySearch(matrix, target, i, false);
            if(v || h)
                return true;
        }
        
        return false;
    }
    
    bool binarySearch(vector<vector<int>>& matrix, int target, int start, int vertical)
    {
        int lo = start;
        int hi = vertical ? matrix[0].size() - 1 : matrix.size() - 1;
        
        while(lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if(vertical)
            {
                if(matrix[start][mid] == target)
                    return true;
                
                if(matrix[start][mid] < target)
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
            else
            {
                if(matrix[mid][start] == target)
                    return true;
                
                if(matrix[mid][start] < target)
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
        }
        
        return false;
    }
};