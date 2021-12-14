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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
       if(l1 == nullptr || l2 == nullptr)
           return l1 == nullptr ? l2 : l1;
        
        ListNode* head;
        if(l1->val < l2->val)
        {
            head = l1;
            l1 = l1->next;
        }    
        else
        {
            head = l2;
            l2 = l2->next;
        }
            
        ListNode* node = head;
        while(l1 != nullptr && l2 != nullptr)
        {
            if(l1->val < l2->val)
            {
                node->next = l1;
                l1 = l1->next;
            }
            else
            {
                node->next = l2;
                l2 = l2->next;
            }
            
            node = node->next;
        }
        
        if(l1 != nullptr)
            node->next = l1;
        if(l2 != nullptr)
            node->next = l2;
        
        return head;
    }
};