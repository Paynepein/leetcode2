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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	if (lists.size() == 0) return nullptr;
    	ListNode *head1 = new ListNode(0);
    	head1->next = lists[0];
    	ListNode *p, *prep, *q, *nexq;
  		for (int i = 1; i < lists.size(); ++i) {
  			if (!lists[i]) continue;
  			prep = head1;
  			p = prep->next;
  			q = lists[i];
  			while (q) {
  				while (p && p->val <= q->val) {
  					prep = prep->next;
  					p = p->next;
  				}
  				if (!p) {
  					prep->next = q;
  					break;
  				}
  				prep->next = q;
  				q = q->next;
  				prep->next->next = p;
  				prep = prep->next;
  			}
  		}   
  		return head1->next;   
    }
};