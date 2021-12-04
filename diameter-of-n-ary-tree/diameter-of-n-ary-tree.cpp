/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    int max_diameter;
public:
    int diameter(Node* root) {
        max_diameter = 0;
        dfs(root);
        return max_diameter;
    }
    
    int dfs(Node* root)
    {
        if(root->children.size() == 0)
            return 1;
        
        int h1 = 0, h2 = 0;
        for(auto c : root->children)
        {
            int h = dfs(c);
            if(h > h1)
            {
                h2= h1;
                h1 = h;
            }
            else if(h > h2)
                h2 = h;
        }
        
        
        int diameter = h1 + h2;
        max_diameter = max(max_diameter, diameter);
        
        return h1 + 1;
    }
};