class Vector2D {
private:
    vector<vector<int>> v; 
    vector<vector<int>>::iterator begin, end;
    vector<int>::iterator curr;


public:
    Vector2D(vector<vector<int>>& vec) {
        v = vec;
        begin = v.begin();
        end = v.end();
        
        if(begin != end)
            curr = begin->begin();
    }
    
    int next() {
        hasNext();
        return *curr++;
    }
    
    bool hasNext() {
        while(begin != end && curr == begin->end())
        {
            begin++;
            if(begin != end)
                curr = begin->begin();
        }
        
        if(begin != end)
            return true;
        else
            return false;
    }
};


/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */