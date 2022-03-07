/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
private:
    list<TreeNode*> l;
    list<TreeNode*>::iterator it;
    
public:
    BSTIterator(TreeNode* root) {
        stack<TreeNode*> s;
        
        while(!s.empty() || root) {
            while(root) {
                s.push(root);
                root = root->left;
            }
            
            root = s.top(); s.pop();
            l.push_back(root);
            root = root->right;
        }
        
        it = l.begin();
    }
    
    int next() {
        int val = (*it)->val;
        it++;
        return val;
    }
    
    bool hasNext() {
        return it != l.end();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */