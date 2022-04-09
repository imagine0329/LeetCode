class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0;
        stack<int> s;
        
        for(int i = 0; i < height.size(); i++) {
            while(!s.empty() && height[i] > height[s.top()]) {
                int top = s.top(); s.pop();
                if(s.empty())
                    break;
                int d = i - s.top() - 1;
                int h = min(height[i], height[s.top()]) - height[top];
                water += (d * h);
            }
            s.push(i);
        }
        
        return water;
    }
};