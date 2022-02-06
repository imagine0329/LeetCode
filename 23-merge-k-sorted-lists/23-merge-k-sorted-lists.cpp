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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        
        int n = lists.size();
        int interval = 1;
        while(interval < n) {
            for(int i = 0; i < n - interval; i += (interval * 2))
                lists[i] = merge(lists[i], lists[i + interval]);
            
            interval *= 2;
        }
        
        return lists[0];
    }
    
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode* dummy = new ListNode();
        ListNode* node = dummy;
        while(a && b) {
            if(a->val <= b->val) {
                node->next = a;
                a = a->next;
            }
            else {
                node->next = b;
                b = b->next;
            }
            
            node = node->next;
        }
        
        if(a)
            node->next = a;
        else if(b)
            node->next = b;
        
        return dummy->next;
    }
};