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
/*  BFS*/
class Solution {
private:
    map<int, vector<pair<int, int>>> m;
    
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr)
            return ans;
        
        queue<pair<int, TreeNode*>> q;
        map<int, vector<int>> m;
        int col = 0;
        
        q.emplace(col, root);
        
        while(!q.empty())
        {
            pair<int, TreeNode*> p = q.front();
            q.pop();
            col = p.first;
            root = p.second;
            
            if(root != nullptr)
            {
                m[col].push_back(root->val);
                if(root->left)
                    q.emplace(col-1, root->left);
                if(root->right)
                    q.emplace(col+1, root->right);
            }
        }
        
        for(auto& k : m)
        {
            ans.push_back(k.second);
        }
        
        return ans;
    }
    
};


/*  DFS
class Solution {
private:
    map<int, vector<pair<int, int>>> m;
    
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr)
            return ans;
        
        dfs(root, 0, 0);
        
        for(auto& col : m)
        {
            vector<int> temp;
            sort(col.second.begin(), col.second.end());
            for(auto& v : col.second)
                temp.push_back(v.second);
            
            ans.push_back(temp);
        }    
        
        return ans;
    }
    
    void dfs(TreeNode* root, int row, int col)
    {
        if(root == nullptr)
            return;
        
        m[col].push_back(make_pair(row, root->val));
        dfs(root->left, row+1, col-1);
        dfs(root->right, row+1, col+1);
    }
    
};*/