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
    ListNode* reverseKGroup(ListNode* head, int k) {
    	if (!head || k <= 1) return head;
        ListNode *next = head, *p, *q;
        int n = k;
        while (n > 0 && next) {
        	next = next->next;
        	--n;
        }
        if (n > 0) return head;
        next = reverseKGroup(next, k);
        p = head, q;
        while (k--) {
        	q = p->next;
        	p->next = next;
        	next = p;
        	p = q;
        }
        return next;
    }
};