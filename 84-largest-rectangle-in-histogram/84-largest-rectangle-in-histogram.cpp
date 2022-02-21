class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        s.push(-1);
        int largest = 0;
        
        for(int i = 0; i < heights.size(); i++) {
            while(s.top() != -1 && heights[s.top()] > heights[i]) {
                int height = heights[s.top()]; s.pop();
                int width = i - s.top() - 1; 
                largest = max(largest, width * height);
            }
            s.push(i);
        }
        
        while(s.top() != -1) {
            int height = heights[s.top()]; s.pop();
            int width = heights.size() - s.top() - 1;
            largest = max(largest, width * height);
        }
        
        return largest;
    }
};