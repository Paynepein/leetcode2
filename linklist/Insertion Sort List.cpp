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
    ListNode* insertionSortList(ListNode* head) {
    	if (!head || !head->next) return head;
    	ListNode *pre = new ListNode(0);
    	pre->next = head;
        ListNode *p = head->next, *last = head, *next, *q;
        while (p) {
        	next = p->next;
        	for (q = pre; q->next != p && q->next->val <= p->val; q = q->next) ;
        	if (q == pre) {
        		pre->next = p;
        		p->next = head;
        		last->next = next;
        		head = p;
        	} else if (q->next != p) {
        		p->next = q->next;
        		q->next = p;
        		last->next = next;
        	} else {
        		last = p;
        	}
        	p = next;
        }
        return head;
    }
};