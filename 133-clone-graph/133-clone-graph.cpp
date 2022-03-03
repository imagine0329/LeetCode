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
        queue<Node*> q;
        
        Node* newNode = new Node(node->val);
        m[newNode->val] = newNode;
        q.push(node);
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                Node* curr = q.front(); q.pop();
                if(m.find(curr->val) == m.end())
                    m[curr->val] = new Node(curr->val);
                
                for(auto& neighbor : curr->neighbors) {
                    int val = neighbor->val;
                    if(m.find(val) == m.end()) {
                        m[val] = new Node(val);
                        q.push(neighbor);
                    }
                    m[curr->val]->neighbors.push_back(m[val]);
                }
            }
        }
        return newNode;
    }
};