/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_map<Node*, Node*> pm, qm;
        Node* node = p;
        
        while(p != nullptr) {
            pm[p] = p->parent;
            p = p->parent;
        }
        while(q != nullptr) {
            qm[q] = q->parent;
            q = q->parent;
        }
        
        while(node != nullptr) {
            if(qm.find(node) != qm.end())
                return node;
            
            node = pm[node];
        }
        
        return nullptr;
    }
};