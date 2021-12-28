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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        
        ListNode* node = new ListNode();
        ListNode* head = node;
        
        while(l1 || l2)
        {
            int x = 0;
            if(l1)
            {
                x += l1->val;
                l1 = l1->next;
            }

            if(l2)
            {
                x += l2->val;
                l2 = l2->next;
            }
            
            x += carry;
            carry = x / 10;
            node->next = new ListNode(x % 10);
            node = node->next;
        }
        
        if(carry)
            node->next = new ListNode(carry);
        
        return head->next;
    }
};