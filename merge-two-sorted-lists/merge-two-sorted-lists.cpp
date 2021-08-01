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
        //ListNode* node = (ListNode*)malloc(sizeof(ListNode));
        ListNode* node = new ListNode();
        ListNode* temp = node;
        
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val >= l2->val)
            {
                node->next = l2;
                l2 = l2->next;
            }
            else
            {
                node->next = l1;
                l1 = l1->next;
            }
            
            node = node->next;
        }
        
        if(l1 == NULL)
            node->next = l2;
        else if(l2 == NULL)
            node->next = l1;
        
        temp = temp->next;
        return temp;
    }
};