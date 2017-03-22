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
    ListNode* deleteDuplicates(ListNode* head) {
    	if (!head || !head->next) return head;
        ListNode *p = head->next, *q = head;
        while (p) {
        	if (q->val == p->val) p = p->next;
        	else {
        		q->next = p;
        		q = p;
        		p = p->next;
        	}
        }
        q->next = p;
        return head;
    }
};