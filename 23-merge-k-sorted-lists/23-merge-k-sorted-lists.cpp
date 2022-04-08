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
        ListNode* ans = nullptr;
        
        for(auto l : lists)
            ans = merge(ans, l);
        
        return ans;
    }
    
    ListNode* merge(ListNode* a, ListNode* b) {
        if(!a || !b) return a ? a : b;
        
        ListNode* node = nullptr;
        if(a->val <= b->val) {
            node = a;
            node->next = merge(a->next, b);
        }
        else {
            node = b;
            node->next = merge(b->next, a);
        }
        return node;
    }
};