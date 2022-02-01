class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> v;
        
        for(auto a : asteroids) {
            while(!v.empty() && v.back() > 0 && v.back() < -a)
                v.pop_back();
            if(v.empty() || a > 0 || v.back() < 0)
                v.push_back(a);
            else if(v.back() == -a)
                v.pop_back();
        }
        
        return v;
    }
};