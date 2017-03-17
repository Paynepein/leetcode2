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
    ListNode* swapPairs(ListNode* head) {
    	if (!head || !head->next) return head;
        ListNode *p = head, *q = head->next, *r = head->next->next;
        q->next = p;
        p->next = swapPairs(r);
        return q;
    }
};