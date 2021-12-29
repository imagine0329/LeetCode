/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        stack<ListNode*> s;
        
        ListNode* node = head;
        ListNode* prev = nullptr;
        head = nullptr;
        while(node)
        {
            while(node && s.size() < k-1)
            {
                s.push(node);
                node = node->next;
            }
            
            if(s.size() < k-1 || node == nullptr)
                break;
            
            if(prev)
                prev->next = node;
            
            if(head == nullptr)
                head = node;
            
            ListNode* next = node->next;
            while(!s.empty())
            {
                node->next = s.top();
                s.pop();
                node = node->next;
            }
            
            prev = node;
            node->next = next;
            node = node->next;
        }
        
        return head;
    }
};