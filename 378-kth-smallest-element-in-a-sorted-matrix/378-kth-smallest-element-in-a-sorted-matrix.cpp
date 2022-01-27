class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<>> q;
        int n = matrix.size();
        for(int row = 0; row < min(n, k); row++)
            q.push({matrix[row][0], row, 0});
        
        int ans;
        for(int i = 0; i < k; i++) {
            auto element = q.top(); q.pop();
            int r = element[1], c = element[2];
            ans = element[0];
            if(c + 1 < n) q.push({matrix[r][c + 1], r, c + 1});
        }
        
        return ans;
    }
};