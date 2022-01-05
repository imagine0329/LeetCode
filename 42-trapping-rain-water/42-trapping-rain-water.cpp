class Solution {
public:
    int trap(vector<int>& height) {
        int area = 0;
        stack<int> s;
        
        int curr = 0;
        while(curr < height.size())
        {
            while(!s.empty() && height[curr] > height[s.top()])
            {
                int top = s.top();
                s.pop();
                if(s.empty())
                    break;
                
                int d = curr - s.top() - 1;
                int h = min(height[curr], height[s.top()]) - height[top];
                area += d * h;
            }
            
            s.push(curr++);
        }
        
        return area;
    }
};