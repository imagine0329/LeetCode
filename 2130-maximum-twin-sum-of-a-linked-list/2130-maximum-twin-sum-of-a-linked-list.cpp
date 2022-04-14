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
    int pairSum(ListNode* head) {
        stack<int> s1, s2;
        while(head) {
            s1.push(head->val);
            head = head->next;
        }
        
        int n = s1.size() / 2;
        while(n--) {
            s2.push(s1.top());
            s1.pop();
        }
        
        int ans = INT_MIN;
        while(!s1.empty()) {
            ans = max(ans, s1.top() + s2.top());
            s1.pop();
            s2.pop();
        }
        
        return ans;
    }
};