class Vector2D {
private:
    queue<int> q;
    
public:
    Vector2D(vector<vector<int>>& vec) {
        for(auto v : vec)
        {
            for(auto i : v)
                q.push(i);
        }
    }
    
    int next() {
        int ans = q.front();
        q.pop();
        
        return ans;
    }
    
    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */