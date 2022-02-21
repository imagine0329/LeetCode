class SegmentTree {
public:
    int start, end, min;
    SegmentTree *left, *right;
    
    SegmentTree(int start, int end) {
        this->start = start;
        this->end = end;
        left = right = nullptr;
    }
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        SegmentTree* root = buildSegmentTree(heights, 0, heights.size() - 1);
        
        return calcArea(heights, 0, heights.size() - 1, root);
    }
    
    int calcArea(vector<int>& heights, int left, int right, SegmentTree* root) {
        if(left > right) return 0;
        
        int minIdx = query(root, heights, left, right);
        return max((right - left + 1) * heights[minIdx], 
                max(calcArea(heights, left, minIdx - 1, root), 
                    calcArea(heights, minIdx + 1, right, root)));
    }
    
    SegmentTree* buildSegmentTree(vector<int>& heights, int start, int end) {
        if(start > end) return nullptr;
        SegmentTree* root = new SegmentTree(start, end);
        if(start == end) {
            root->min = start;
            return root;
        }
        
        int mid = (start + end) / 2;
        root->left = buildSegmentTree(heights, start, mid);
        root->right = buildSegmentTree(heights, mid + 1, end);
        root->min = heights[root->left->min] < heights[root->right->min] ? root->left->min : root->right->min;
        return root;
    }
    
    int query(SegmentTree* root, vector<int>& heights, int start, int end) {
        if(!root || end < root->start || start > root->end) return -1;
        if(start <= root->start && end >= root->end) return root->min;
        
        int left = query(root->left, heights, start, end);
        int right = query(root->right, heights, start, end);
        if(left == - 1) return right;
        if(right == -1) return left;
        return heights[left] < heights[right] ? left : right;
    }
};