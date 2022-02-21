struct Cell {
    Cell(int r, int c) : r(r), c(c) {}
    Cell(Cell& p) : r(p.r), c(p.c) {}
    Cell(){}
    
    bool operator==(const Cell& a) {
        return a.r == r && a.c == c;
    }
    
    int r, c;
};

class SegmentTree {
public:
    Cell start, end;
    vector<SegmentTree*> part;
    int sum;
    
    SegmentTree(Cell& start, Cell& end) : start(start), end(end){
        this->part = vector<SegmentTree*>(4, nullptr);
        this->sum = 0;
    }
};

class NumMatrix {
private:
    SegmentTree* root;
    
public:
    NumMatrix(vector<vector<int>>& matrix) {
        root = buildTree(matrix, Cell(0, 0), Cell(matrix.size() - 1, matrix[0].size() - 1));
    }
    
    void update(int row, int col, int val) {
        updateTree(root, Cell(row, col), val);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return query(root, Cell(row1, col1), Cell(row2, col2));
    }
    
    SegmentTree* buildTree(vector<vector<int>>& matrix, Cell start, Cell end) {
        if(start.r > end.r || start.c > end.c) return nullptr;
    
        SegmentTree* node = new SegmentTree(start, end);
        if(start == end) {
            node->sum = matrix[start.r][start.c];
            return node;
        }
        
        int r_mid = (start.r + end.r) / 2;
        int c_mid = (start.c + end.c) / 2;
        
        node->part[0] = buildTree(matrix, start, Cell(r_mid, c_mid));
        node->part[1] = buildTree(matrix, Cell(start.r, c_mid + 1), Cell(r_mid, end.c));
        node->part[2] = buildTree(matrix, Cell(r_mid + 1, start.c), Cell(end.r, c_mid));
        node->part[3] = buildTree(matrix, Cell(r_mid + 1, c_mid + 1), end);
        
        node->sum += node->part[0] ? node->part[0]->sum : 0;
        node->sum += node->part[1] ? node->part[1]->sum : 0;
        node->sum += node->part[2] ? node->part[2]->sum : 0;
        node->sum += node->part[3] ? node->part[3]->sum : 0;
        
        return node;
    }
    
    int query(SegmentTree* root, Cell start, Cell end) {
        if(!root) return 0;
        if(root->end.r < start.r || root->end.c < start.c ||
            root->start.r > end.r || root->start.c > end.c)
            return 0;
        
        if(root->start.r >= start.r && root->start.c >= start.c &&
            root->end.r <= end.r && root->end.c <= end.c)
            return root->sum;
        
        return query(root->part[0], start, end) + query(root->part[1], start, end) +
                query(root->part[2], start, end) + query(root->part[3], start, end);
    }
    
    void updateTree(SegmentTree* root, Cell cell, int val) {
        if(!root) return;
        if(root->start.r > cell.r || root->start.c > cell.c ||
            root->end.r < cell.r || root->end.c < cell.c)
            return;
        
        if(root->start.r == cell.r && root->start.c == cell.c &&
            root->end.r == cell.r && root->end.c == cell.c) {
            root->sum = val;
            return;
        }
        
        updateTree(root->part[0], cell, val);
        updateTree(root->part[1], cell, val);
        updateTree(root->part[2], cell, val);
        updateTree(root->part[3], cell, val);
        
        root->sum = 0;
        root->sum += root->part[0] ? root->part[0]->sum : 0;
        root->sum += root->part[1] ? root->part[1]->sum : 0;
        root->sum += root->part[2] ? root->part[2]->sum : 0;
        root->sum += root->part[3] ? root->part[3]->sum : 0;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */