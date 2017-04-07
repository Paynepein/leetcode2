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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *pre = new ListNode(0), *p = pre;
        pre->next = head;
        while (p->next) {
        	if (p->next->val == val) {
        		p->next = p->next->next;
        	} else {
        		p = p->next;
        	}
        }
        return pre->next;
    }
};