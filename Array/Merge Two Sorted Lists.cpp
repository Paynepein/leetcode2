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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
  		ListNode *head = new ListNode(0), *last = head;
  		while (l1 && l2) {
  			if (l1->val < l2->val) {
  				last->next = new ListNode(l1->val);
  				l1 = l1->next;
  			} else {
  				last->next = new ListNode(l2->val);
  				l2 = l2->next;
  			}
  			last = last->next;
  		}
  		if (l1) last->next = l1;
  		else if (l2) last->next = l2;
  		return head->next;   
    }
};