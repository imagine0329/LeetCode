/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> m;
    
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr)
            return nullptr;
        
        if(m.find(head) != m.end())
            return m[head];
        
        Node* node = new Node(head->val);
        m[head] = node;
        
        node->next = copyRandomList(head->next);
        node->random = copyRandomList(head->random);
        
        return node;
    }
};