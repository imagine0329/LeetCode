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
public:
    Node* copyRandomList(Node* head) {
        Node* dummy = new Node(0);
        Node* copied = dummy;
        unordered_map<Node*, Node*> m;
        
        while(head) {
            if(m.find(head) == m.end())
                m[head] = new Node(head->val);
            
            copied->next = m[head];
            copied = copied->next;
            if(!head->random)
                copied->random = nullptr;
            else {
                if(m.find(head->random) == m.end())
                    m[head->random] = new Node(head->random->val);
                
                copied->random = m[head->random];
            }
            
            head = head->next;
        }
        return dummy->next;
    }
};