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
public:
    int diameter(Node* root) {
        int longest = 0;
        dfs(root, longest, 0);
        return longest;
    }
    
    int dfs(Node* root, int& longest, int depth) {
        if(root == nullptr)
            return depth;
        
        int first = depth, second = 0;
        for(auto node : root->children) {
            int ret = dfs(node, longest, depth + 1);
            if(ret > first) {
                second = first;
                first = ret;
            }
            else if(ret > second)
                second = ret;
        }
        
        longest = max(longest, first + second - (2 * depth));
        
        return first;
    }
};



