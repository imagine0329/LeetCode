class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> q;
        
        for(auto m : matrix) {
            for(auto n : m) {
                q.push(n);
                if(q.size() > k)
                    q.pop();
            }
        }
        
        return q.top();
    }
};