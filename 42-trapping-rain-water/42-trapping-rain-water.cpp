class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0;
        stack<int> s;
        
        for(int i = 0; i < height.size(); i++) {
            while(!s.empty() && height[s.top()] < height[i]) {
                int curr = s.top(); s.pop();
                if(s.empty())
                    break;
                
                int h = min(height[s.top()], height[i]) - height[curr];
                int w = i - s.top() - 1;
                water += h * w;
            }
            
            s.push(i);
        }
        return water;
    }
};

/*
                i
height = [2,1,0,2,1,0,1,3,2,1,2,1]

stack
top <---> bottom
index:  0   1
value:  2   1
    
right height = 2
current height = 0
left height = 1
    
height = min(right_h, left_h) - curr_h
width = i - stack.top()
*/