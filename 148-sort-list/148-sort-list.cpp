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
    ListNode* sortList(ListNode* head) {
        multimap<int, ListNode*> m;
        ListNode* node = head;
        
        while(node) {
            m.insert({node->val, node});
            node = node->next;
        }
        
        ListNode* prev = nullptr;
        node = nullptr;
        for(auto n : m) {
            if(prev) prev->next = n.second;
            if(!node) node = n.second;
            prev = n.second;
        }
        
        if(prev) prev->next = nullptr;
        
        return node;
    }
};