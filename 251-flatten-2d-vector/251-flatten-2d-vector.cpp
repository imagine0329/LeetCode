class Vector2D {
private:
    int inner = 0, outer = 0;
    vector<vector<int>> vec;
    
public:
    Vector2D(vector<vector<int>>& vec) {
        this->vec = vec;
    }
    
    int next() {
        hasNext();
        return vec[outer][inner++];
    }
    
    bool hasNext() {
        while(outer != vec.size() && inner >= vec[outer].size()) {
            outer++;
            if(outer != vec.size())
                inner = 0;
        }
        
        return outer != vec.size();
    }
};


/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */