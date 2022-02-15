typedef pair<int, pair<int, int>> t;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<t, vector<t>, greater<t>> q;
        
        for(int r = 0; r < n; r++)
            q.push({matrix[r][0], {r, 0}});
        
        int ans;
        while(k--) {
            auto cell = q.top(); q.pop();
            ans = cell.first;
            int r = cell.second.first, c = cell.second.second;
            if(c + 1 < n)
                q.push({matrix[r][c + 1], {r, c + 1}});
        }
        
        return ans;
    }
};