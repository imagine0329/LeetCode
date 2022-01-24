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
        dfs(root, longest);
        return longest;
    }
    
    int dfs(Node* root, int& longest) {
        if(root == nullptr)
            return 0;
        
        vector<int> heights;
        for(auto node : root->children) {
            int ret = dfs(node, longest);
            heights.push_back(ret);
        }
        
        sort(heights.begin(), heights.end(), [](int& a, int& b) {
            return a > b;
        });
        
        int first = heights.size() > 0 ? heights[0] : 0;
        int second = heights.size() > 1 ? heights[1] : 0;
        longest = max(longest, first + second);
        
        return max(first, second) + 1;
    }
};