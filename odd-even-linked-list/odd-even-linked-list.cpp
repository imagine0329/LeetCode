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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        
        bool check = true;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;
        ListNode* curr = head->next->next;
        
        while(curr != nullptr)
        {
            if(check)
            {
                odd->next = curr;
                odd = odd->next;
            }
            else
            {
                even->next = curr;
                even = even->next;
            }
            
            check = !check;
            curr = curr->next;
        }
        
        if(!check)
            even->next = nullptr;
            
        
        odd->next = evenHead;
        
        return head;
    }
};