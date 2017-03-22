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
  		int val = 0;
  		ListNode *pre = new ListNode(-1), *last = pre, *p = head, *q;
  		pre->next = head;
  		while (p && p->next) {
  			if (p->val != p->next->val) {
  				last = p;
  				p = p->next;
  			} else {
  				while (p && p->val == last->next->val) p = p->next;
  				last->next = p;
  			}
  		}
  		return pre->next;
    }
};