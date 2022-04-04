/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, unordered_set<int>> graph;
        preorder(root, nullptr, graph);
        
        queue<int> q;
        vector<int> ans;
        unordered_set<int> visited;
        
        q.push(target->val);
        visited.insert(target->val);
        int dist = 0;
        while(dist <= k && !q.empty()) {
            int n = q.size();
            while(n--) {
                int u = q.front(); q.pop();
                if(dist == k)
                    ans.push_back(u);
                else {
                    for(auto v : graph[u]) {
                        if(visited.find(v) == visited.end()) {
                            q.push(v);
                            visited.insert(v);
                        }
                    }
                }
            }
            dist++;
        }
        return ans;
    }
    
    void preorder(TreeNode* root, TreeNode* parent, unordered_map<int, unordered_set<int>>& graph) {
        if(!root) return;
        if(parent) {
            graph[root->val].insert(parent->val);
            graph[parent->val].insert(root->val);
        }
        
        preorder(root->left, root, graph);
        preorder(root->right, root, graph);
    }
};