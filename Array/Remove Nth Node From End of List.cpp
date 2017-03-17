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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head, *q;
        ListNode *pre = new ListNode(0);
        pre->next = head;
        q = pre;
        while (n-- > 1 && p) {
        	p = p->next;
        }
        if (n > 0) return head;
        while (p->next) {
        	p = p->next;
        	q = q->next;
        }
        q->next = q->next->next;
        return pre->next;
    }
};