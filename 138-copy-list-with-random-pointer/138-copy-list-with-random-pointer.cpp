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
    
    Node* getClonedNode(Node* node)
    {
        if(node == nullptr)
            return nullptr;
        
        if(m.find(node) != m.end())
            return m[node];
        
        m[node] = new Node(node->val);
        
        return m[node];
    }
    
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr)
            return nullptr;
        
        Node* newHead = new Node(head->val);
        Node* node = newHead;
        m[head] = newHead;
        
        while(head)
        {
            node->next = getClonedNode(head->next);
            node->random = getClonedNode(head->random);
            node = node->next;
            head = head->next;
        }
        
        return newHead;
    }
};