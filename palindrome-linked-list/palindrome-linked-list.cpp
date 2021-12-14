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
    bool isPalindrome(ListNode* head) {
        ListNode* node = head;
        
        int length = 0;
        while(node)
        {
            node = node->next;
            length++;
        }
        
        stack<int> s;
        node = head;
        for(int i=0; i<length/2; i++)
        {
            s.push(node->val);
            node = node->next;
        }
        
        if(length % 2)
            node = node->next;
        
        while(node)
        {
            if(s.top() != node->val)
                return false;
            
            node = node->next;
            s.pop();
        }
        
        return true;
    }
};