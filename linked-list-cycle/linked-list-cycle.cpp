/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr)
            return false;
        
        ListNode *slow = head, *fast = head->next;
        
        while(slow != fast && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if(!fast || !fast->next)
            return false;
        
        return true;
    }
};