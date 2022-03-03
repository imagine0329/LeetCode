/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        unordered_map<int, Node*> m;
        
        Node* newNode = new Node(node->val);
        m[newNode->val] = newNode;
        dfs(node, m);
        return newNode;
    }
    
    void dfs(Node* node, unordered_map<int, Node*>& m) {
        for(auto& neighbor : node->neighbors) {
            int val = neighbor->val;
            if(m.find(val) == m.end()) {
                m[val] = new Node(val);
                dfs(neighbor, m);
            }
            m[node->val]->neighbors.push_back(m[val]);
        }
    }
        
        
        
        
        
};