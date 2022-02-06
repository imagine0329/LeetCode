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
        
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> q;
        for(auto list : lists) {
            while(list) {
                q.push({list->val, list});
                list = list->next;
            }
        }
        
        ListNode* dummy = new ListNode();
        ListNode* node = dummy;
        while(!q.empty()) {
            node->next = q.top().second; q.pop();
            node = node->next;
        }
        
        return dummy->next;
    }
};