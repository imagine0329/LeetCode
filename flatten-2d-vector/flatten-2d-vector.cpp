/*  1st
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
};*/

/*  2nd*/
class Vector2D {
private:
    vector<vector<int>>::iterator start, end;
    vector<int>::iterator inner;
    
public:
    Vector2D(vector<vector<int>>& vec) {
        start = vec.begin();
        end = vec.end();
        if(start != end)
            inner = start->begin();
    }
    
    int next() {
        hasNext();
        return *inner++;
    }
    
    bool hasNext() {
        while(start != end && inner == start->end())
        {
            ++start;
            if(start != end)
                inner = start->begin();
        }
        
        return start != end;
    }
};


/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */